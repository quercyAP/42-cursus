import subprocess
import re
import signal
from time import sleep
import queue
import plotly.figure_factory as ff
import plotly.graph_objs as go
import threading
from contextlib import contextmanager
import os
import time
import dash
from dash import dcc, html
from dash.dependencies import Input, Output, State
from dash.exceptions import PreventUpdate

def stdout_reader(process, stdout_queue, stop_event):
    while not stop_event.is_set():
        line = process.stdout.readline()
        if line:
            stdout_queue.put(line)
        else:
            break

def run_philo_test(args, execution_timeout):
    process = subprocess.Popen(['./philo'] + args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf8', bufsize=1, universal_newlines=True)

    stdout_queue = queue.Queue()
    stop_event = threading.Event()
    stdout_thread = threading.Thread(target=stdout_reader, args=(process, stdout_queue, stop_event))
    stdout_thread.start()

    stdout_thread.join(timeout=execution_timeout)

    if stdout_thread.is_alive():
        stop_event.set()
        process.terminate()
        process.wait()

    stdout_lines = []
    while not stdout_queue.empty():
        stdout_lines.append(stdout_queue.get())

    stdout = "".join(stdout_lines)
    stderr = process.stderr.read()

    # Affiche la sortie et les erreurs dans le terminal
    print("Sortie:")
    print(stdout)
    print("Erreurs:")
    print(stderr)

    return stdout, stderr

def analyze_logs(logs):
    pattern = r'(\d+) (\d+) (has taken a fork|is eating|is sleeping|is thinking|died)'
    matches = re.findall(pattern, logs)

    results = {}
    for timestamp, philosopher, action in matches:
        if philosopher not in results:
            results[philosopher] = []

        results[philosopher].append((int(timestamp), action))

    return results if results else {}

def general_evaluate_test(args, results):
    num_philosophers = int(args[0])
    time_to_die = int(args[1])
    time_to_eat = int(args[2])
    time_to_sleep = int(args[3])
    num_eat = int(args[4]) if len(args) > 4 else None

    philo_died = any([event[1] == "died" for events in results.values() for event in events])

    if num_eat is None:
        if time_to_die > (time_to_eat + time_to_sleep) and time_to_die > time_to_eat:
            return not philo_died
        elif num_philosophers > 1 and (time_to_die < (time_to_eat + time_to_sleep) or time_to_die < time_to_eat):
            return philo_died
        else:
            return None
    else:
        if philo_died:
            return False
        for events in results.values():
            eating_count = sum([1 for event in events if event[1] == "is eating"])
            if eating_count < num_eat:
                return False
        return True

def plot_results(results, logs, args):  
    colors = {
        "has taken a fork": "rgb(0, 0, 255)",
        "is eating": "rgb(0, 255, 0)",
        "is sleeping": "rgb(255, 0, 0)",
        "is thinking": "rgb(255, 255, 0)",
        "died": "rgb(0, 0, 0)"
    }

    fig = go.Figure()

    for action, color in colors.items():
        fig.add_trace(go.Scatter(x=[None], y=[None], mode='markers',
                                 marker=dict(size=10, color=color),
                                 showlegend=True, name=action))

    action_offset = {
        "has taken a fork": 0,
        "is eating": 1,
        "is sleeping": 2,
        "is thinking": 3,
        "died": 4
    }

    for philosopher, events in results.items():
        for i in range(len(events) - 1):
            start = events[i][0]
            end = events[i + 1][0]
            action = events[i][1]
            y_offset = action_offset[action]

            fig.add_shape(type="rect",
                          x0=start, x1=end, y0=int(philosopher) * 5 + y_offset - 0.5,
                          y1=int(philosopher) * 5 + y_offset + 0.5,
                          fillcolor=colors[action],
                          line=dict(width=0),
                          yref="y",
                          xref="x")

        fig.add_trace(go.Scatter(x=[0], y=[int(philosopher) * 5 + 1.5], text=[philosopher], mode="text", showlegend=False))

    fig.update_layout(
        title="Philo Test Results",
        xaxis_title="Time (ms)",
        yaxis_title="Philosopher",
        yaxis=dict(tickmode="array", tickvals=[int(philosopher) * 5 + 1.5 for philosopher in results.keys()]),
        height=max(len(results) * 80, 200),
        shapes=dict(layer="below")
    )

    return fig

# Créez une application Dash
app = dash.Dash(__name__)

app.layout = html.Div([
    html.H1("Philosopher Test Visualizer", style={"text-align": "center", "color": "#2a9d8f", "font-family": "Arial, Helvetica, sans-serif", "margin-bottom": "30px"}),
    dcc.Graph(id='gantt_chart', style={"border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "10px"}),  # Graphique de Gantt
    html.Br(),
    html.Div([
        html.Label('Logs:', style={"font-weight": "bold", "font-family": "Arial, Helvetica, sans-serif", "font-size": "18px", "color": "#2a9d8f"}),
        html.Div([
            dcc.Textarea(id='logs_area', readOnly=True, style={'width': '100%', 'height': '200px', 'border': '1px solid #e0e0e0', 'border-radius': '5px', 'padding': '5px', 'font-family': 'Courier, monospace'})
        ], style={"border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "10px", "background-color": "#ffffff"}),
    ], style={"background-color": "#f0f0f0", "border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "20px", "box-shadow": "0 4px 6px rgba(0, 0, 0, 0.1)"}),
    html.Br(),
    html.Label('Test Parameters:', style={"font-weight": "bold", "font-family": "Arial, Helvetica, sans-serif", "font-size": "18px", "color": "#2a9d8f"}),
    html.Div([
        dcc.Input(id='num_philosophers', type='number', placeholder='Number of philosophers', style={"margin-right": "10px", "border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "5px"}),
        dcc.Input(id='time_to_die', type='number', placeholder='Time to die', style={"margin-right": "10px", "border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "5px"}),
        dcc.Input(id='time_to_eat', type='number', placeholder='Time to eat', style={"margin-right": "10px", "border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "5px"}),
        dcc.Input(id='time_to_sleep', type='number', placeholder='Time to sleep', style={"margin-right": "10px", "border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "5px"}),
        dcc.Input(id='num_eat', type='number', placeholder='Number of times each philosopher must eat (optional)', style={"margin-right": "10px", "border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "5px"})
    ], style={"background-color": "#ffffff", "border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "20px", "box-shadow": "0 4px 6px rgba(0, 0, 0, 0.1)"}),
    html.Br(),
	html.Div([
    html.Div(id="progress_bar", style={"background-color": "#2a9d8f", "height": "5px", "width": "0%"})  # Ajout de la barre de progression
	], style={"background-color": "#e0e0e0", "height": "5px", "width": "100%", "border-radius": "5px"}),
	html.Div([
    html.Div(id="progress_bar", style={"background-color": "#2a9d8f", "height": "5px", "width": "0%"}, **{"data-progress": 0})
	], style={"background-color": "#e0e0e0", "height": "5px", "width": "100%", "border-radius": "5px"}),
    html.Div([
    html.Label('Execution Timeout (seconds):', style={"font-weight": "bold", "font-family": "Arial, Helvetica, sans-serif", "font-size": "18px", "color": "#2a9d8f"}),
    html.Div([
		dcc.Interval(id='progress_interval', interval=1000),  # intervalle de 1000 ms (1 seconde)
        dcc.Input(id='execution_timeout', type='number', value=10, min=1, step=1, style={"border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "5px"})
    	], style={"background-color": "#ffffff", "border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "20px", "box-shadow": "0 4px 6px rgba(0, 0, 0, 0.1)"})
	], style={"background-color": "#f0f0f0", "border": "1px solid #e0e0e0", "border-radius": "5px", "padding": "20px", "box-shadow": "0 4px 6px rgba(0, 0, 0, 0.1)", "margin-bottom": "10px"}),
    html.Button('Run Test', id='run_test_button', style={'background-color': '#2a9d8f', 'color': 'white', 'border': 'none', 'cursor': 'pointer', 'padding': '14px 28px', 'font-size': '16px', 'text-align': 'center', 'transition-duration': '0.4s', 'border-radius': '5px', 'font-family': 'Arial, Helvetica, sans-serif', 'box-shadow': '0 4px 6px rgba(0, 0, 0, 0.1)', 'margin-top': '10px'})  # Bouton pour exécuter le test
	], style={"padding": "30px", "background-color": "#fafafa"})


@app.callback(
    [Output("progress_bar", "style"), Output("progress_bar", "data-progress")],
    [Input("run_test_button", "n_clicks"), Input("progress_interval", "n_intervals")],
    [State("progress_bar", "data-progress"), State('execution_timeout', 'value')],
)
def update_progress_bar(n_clicks, n_intervals, current_progress, execution_timeout):
    ctx = dash.callback_context

    if not ctx.triggered:
        raise PreventUpdate
    else:
        trigger_id = ctx.triggered[0]["prop_id"].split(".")[0]

    if trigger_id == "run_test_button":
        new_progress = 0
        start_time = time.time()
        return (
            {"background-color": "#2a9d8f", "height": "5px", "width": f"{new_progress}%"},
            new_progress,
        )

    elif trigger_id == "progress_interval":
        elapsed_time = time.time() - start_time
        if elapsed_time >= execution_timeout:
            new_progress = 100
        else:
            new_progress = int(elapsed_time / execution_timeout * 100)
        return (
            {"background-color": "#2a9d8f", "height": "5px", "width": f"{new_progress}%"},
            new_progress,
        )

    else:
        raise PreventUpdate


# Mettez à jour le graphique et les logs lorsque le bouton 'Run Test' est cliqué
@app.callback(
    [Output('gantt_chart', 'figure'), Output('logs_area', 'value')],
    [Input('run_test_button', 'n_clicks')],
    [dash.dependencies.State('num_philosophers', 'value'),
     dash.dependencies.State('time_to_die', 'value'),
     dash.dependencies.State('time_to_eat', 'value'),
     dash.dependencies.State('time_to_sleep', 'value'),
     dash.dependencies.State('num_eat', 'value'),
     dash.dependencies.State('execution_timeout', 'value')]
)
def run_test_and_update_chart(n_clicks, num_philosophers, time_to_die, time_to_eat, time_to_sleep, num_eat, execution_timeout):
    if n_clicks is None:
        return go.Figure(), ""

    args = [str(num_philosophers), str(time_to_die), str(time_to_eat), str(time_to_sleep)]
    if num_eat is not None:
        args.append(str(num_eat))

    # Affichez la barre de progression pendant l'exécution du test
    for i in range(execution_timeout):
        sleep(1)
        progress = (i + 1) / execution_timeout
        app.clientside_callback(
            f"document.getElementById('progress_bar').style.width = '{progress * 100}%';",
            Output("dummy", "children"),
            Input("dummy", "children")
        )

    stdout, stderr = run_philo_test(args, execution_timeout)
    results = analyze_logs(stdout)
    fig = plot_results(results, stdout, args)
    num_actions = 4  # Nombre d'actions (prendre une fourchette, manger, dormir, penser)
    fig.update_layout(height=len(results) * num_actions * 20)  # Mettre à jour la hauteur du graphique
    
    evaluation = general_evaluate_test(args, results)
    philo_died = any([event[1] == "died" for events in results.values() for event in events])
    if evaluation is None:
        return fig, stdout
    elif evaluation:
        if philo_died:
            return fig, f"Test réussi\n\n{stdout}"
        else:
            return fig, f"Test échoué : aucun philosophe n'aurait du mourir\n\n{stdout}"
    else:
        if not philo_died:
            return fig, f"Test échoué : un philosophe aurait dû mourir\n\n{stdout}"
        elif philo_died:
            return fig, f"Test réussi\n\n{stdout}"

if __name__ == '__main__':
    app.run_server(debug=True)
