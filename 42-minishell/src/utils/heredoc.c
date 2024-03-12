/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:15:11 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/14 14:50:24 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	here_job(char *key, char *buff, int *fd)
{
	*fd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		buff = readline("> ");
		if (!buff)
			break ;
		if (!ft_strncmp(buff, key, (ft_strlen(key) + 1)))
		{
			if (buff)
				free(buff);
			break ;
		}
		if (buff)
		{
			write(*fd, buff, ft_strlen(buff));
			write(*fd, "\n", 1);
			free(buff);
		}
		else
			write(*fd, "", 0);
	}
}

static void	hasbeen_signaled(t_launch *tool, t_cmd *cmd)
{
	ft_putchar_fd('\n', 1);
	tool->heredoc_killed = TRUE;
	tool->run = FALSE;
	cmd->data->state = 1;
}

void	heredoc(char *key, t_launch *tool, t_cmd *cmd)
{
	pid_t			pid;
	struct termios	term;
	int				fd;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHO;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		here_job(key, NULL, &fd);
		close(fd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &(cmd->data->state), 0);
		if (WIFSIGNALED(cmd->data->state))
			hasbeen_signaled(tool, cmd);
	}
	rl_replace_line("", 1);
	rl_on_new_line();
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
