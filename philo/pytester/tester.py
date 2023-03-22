import subprocess
import re
import plotly.figure_factory as ff
import plotly.graph_objs as go
import dash
from dash import dcc
from dash import html
from dash.dependencies import Input, Output

def run_philo_test(args, show_logs=False):
    process = subprocess.Popen(['../philo'] + args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()

    if show_logs:
        print("\nLogs:")
        print(stdout.decode('utf-8'))

    return stdout.decode('utf-8'), stderr.decode('utf-8'), process.returncode

def analyze_logs(logs):
    pattern = r'(\d+) (\d+) (has taken a fork|is eating|is sleeping|is thinking|died)'
    matches = re.findall(pattern, logs)

    results = {}
    for timestamp, philosopher, action in matches:
        if philosopher not in results:
            results[philosopher] = []

        results[philosopher].append((int(timestamp), action))

    return results

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

def plot_results(results, logs):
    colors = {
        "has taken a fork": "rgb(0, 0, 255)",
        "is eating": "rgb(0, 255, 0)",
        "is sleeping": "rgb(255, 0, 0)",
        "is thinking": "rgb(255, 255, 0)",
        "died": "rgb(0, 0, 0)"
    }

    fig = go.Figure()

    # Ajoutez ces lignes pour créer des marqueurs de légende pour chaque couleur
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
        simultaneous_actions = {}
        for i in range(len(events) - 1):
            start = events[i][0]
            end = events[i + 1][0]
            action = events[i][1]

            if start not in simultaneous_actions:
                simultaneous_actions[start] = []

            simultaneous_actions[start].append((end, action))

        for start, actions in simultaneous_actions.items():
            for i, (end, action) in enumerate(actions):
                y_offset = action_offset[action]

                fig.add_shape(type="rect",
                              x0=start, x1=end, y0=int(philosopher) * 5 + y_offset + i * 0.2 - 0.5,
                              y1=int(philosopher) * 5 + y_offset + i * 0.2 + 0.5,
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
        height=len(results) * 80,
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
    html.Button('Run Test', id='run_test_button', style={'background-color': '#2a9d8f', 'color': 'white', 'border': 'none', 'cursor': 'pointer', 'padding': '14px 28px', 'font-size': '16px', 'text-align': 'center', 'transition-duration': '0.4s', 'border-radius': '5px', 'font-family': 'Arial, Helvetica, sans-serif', 'box-shadow': '0 4px 6px rgba(0, 0, 0, 0.1)', 'margin-top': '10px'})  # Bouton pour exécuter le test
], style={"padding": "30px", "background-color": "#fafafa"})



# Mettez à jour le graphique et les logs lorsque le bouton 'Run Test' est cliqué
@app.callback(
    [Output('gantt_chart', 'figure'), Output('logs_area', 'value')],
    [Input('run_test_button', 'n_clicks')],
    [dash.dependencies.State('num_philosophers', 'value'),
     dash.dependencies.State('time_to_die', 'value'),
     dash.dependencies.State('time_to_eat', 'value'),
     dash.dependencies.State('time_to_sleep', 'value'),
     dash.dependencies.State('num_eat', 'value')]
)

def run_test_and_update_chart(n_clicks, num_philosophers, time_to_die, time_to_eat, time_to_sleep, num_eat):
    if n_clicks is None:
        return go.Figure(), ""

    args = [str(num_philosophers), str(time_to_die), str(time_to_eat), str(time_to_sleep)]
    if num_eat is not None:
        args.append(str(num_eat))

    stdout, stderr, returncode = run_philo_test(args)
    if returncode == 0:
        results = analyze_logs(stdout)
        fig = plot_results(results, stdout)
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

    else:
        return go.Figure(), f"Error: {stderr}"




if __name__ == '__main__':
    app.run_server(debug=True)
