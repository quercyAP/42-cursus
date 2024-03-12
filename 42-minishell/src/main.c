/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:37 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/23 09:40:14 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data, int argc, char **argv, char **penv)
{
	(*data).list_cmd = NULL;
	(*data).prompt_tab = NULL;
	(*data).request_quit = FALSE;
	(*data).quotes = CLOSED;
	(*data).s_quotes = CLOSED;
	(*data).d_quotes = CLOSED;
	(*data).main_argc = argc;
	(*data).main_argv = argv;
	(*data).list_env = set_listenv(penv);
	(*data).state = 0;
	if (argv[1] && !ft_strncmp(argv[1], "-d", 3))
		(*data).debug = TRUE;
	else
		(*data).debug = FALSE;
	if (argv[2] && !ft_strncmp(argv[2], "-e", 3))
		(*data).d_env = TRUE;
	else
		(*data).d_env = FALSE;
	(*data).error = NONE;
}

void	raz(t_data *data)
{
	(*data).quotes = CLOSED;
	(*data).s_quotes = CLOSED;
	(*data).d_quotes = CLOSED;
	(*data).error = NONE;
	free_list(&(data->list_cmd));
}

void	wait_fork(void *arg)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)arg;
	if (cmd->pid)
		waitpid(cmd->pid, &(cmd->data->state), 0);
	if (cmd->pipe_in)
		close((*(cmd->pipe_in))[WAY_OUT]);
	if (cmd->pipe_out)
		close((*(cmd->pipe_out))[WAY_IN]);
	cmd->data->state %= 255;
}

int	main(int argc, char *argv[], char *penv[])
{
	t_data	data;

	init_data(&data, argc, argv, penv);
	signal_manager(&data);
	while (1)
	{
		data.prompt_tab = ft_readline(&data);
		if (!data.prompt_tab)
		{
			if (data.request_quit)
				exit_main(&data);
			else
				continue ;
		}
		data.list_cmd = parser2000(&data);
		if (!data.list_cmd)
			continue ;
		display_list(data.list_cmd);
		rev(data.list_cmd, data);
		ft_lstiter(data.list_cmd, &wait_fork);
		raz(&data);
	}
}
