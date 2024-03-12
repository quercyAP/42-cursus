/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:19:23 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/06 12:41:59 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	pid_t	id;

	id = waitpid(-1, NULL, WNOHANG);
	if (id < 0)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (id > 1)
		ft_putstr_fd("\n", 1);
}

void	handle_sigquit(int sig)
{
	return ;
}

void	signal_manager(t_data *data)
{
	rl_catch_signals = 0;
	data->sa.sa_handler = handle_sigint;
	data->sa.sa_flags = SA_RESTART;
	sigemptyset(&data->sa.sa_mask);
	sigaction(SIGINT, &data->sa, &data->old_sa);
	signal(SIGQUIT, &handle_sigquit);
}
