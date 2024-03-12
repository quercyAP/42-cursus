/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:13:13 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/23 10:02:27 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cmd_error(t_cmd *cmd)
{
	if (cmd->cmd_type == UNKNOWN)
	{
		cmd->data->error = NOT_FOUND_ERROR;
		ms_perror(cmd->cmd, NOT_FOUND_ERROR);
		cmd->data->state = 127;
	}
}

static void	launch_cmd(t_cmd *cmd, t_launch tool)
{
	if ((cmd->cmd_type == UNKNOWN || cmd->cmd_type == NO_ONE) && tool.run)
		cmd_error(cmd);
	else if (cmd->cmd_type == B_ECHO && tool.run)
		ms_echo(cmd);
	else if (cmd->cmd_type == B_CD && tool.run)
		ms_cd(cmd);
	else if (cmd->cmd_type == B_PWD && tool.run)
		ms_pwd(cmd);
	else if (cmd->cmd_type == B_UNSET && tool.run)
		ms_unset(cmd);
	else if (cmd->cmd_type == B_ENV && tool.run)
		ms_env(cmd);
	else if (cmd->cmd_type == B_EXPORT && tool.run)
		ms_export(cmd);
	else if (cmd->cmd_type == B_EXIT && tool.run)
		ms_exit(cmd);
	else if (cmd->cmd_type == OTHER && tool.run)
		exec_other(cmd);
}

static void	forked(t_cmd *cmd, t_launch tool)
{
	if (cmd->pipe_out)
	{
		dup2((*(cmd->pipe_out))[WAY_IN], STDOUT_FILENO);
		close((*(cmd->pipe_out))[WAY_OUT]);
	}
	if (cmd->pipe_in)
	{
		dup2((*(cmd->pipe_in))[WAY_OUT], STDIN_FILENO);
		close((*(cmd->pipe_in))[WAY_IN]);
	}
	launch_cmd(cmd, tool);
	exit(cmd->data->state);
}

void	launcher(void *arg)
{
	t_cmd		*cmd;
	t_launch	tool;

	tool.run = TRUE;
	tool.heredoc_killed = FALSE;
	tool.save_fd_stdout = dup(STDOUT_FILENO);
	tool.save_fd_stdin = dup(STDIN_FILENO);
	cmd = (t_cmd *)arg;
	manag_redir(cmd, &tool);
	if ((cmd->pipe_out && !(cmd->lst_redir_out))
		|| (cmd->pipe_in && !(cmd->lst_redir_in)))
		cmd->pid = fork();
	if (cmd->pid == 0)
		forked(cmd, tool);
	else if (cmd->pid == -2)
		launch_cmd(cmd, tool);
	if (cmd->pipe_in)
		close((*(cmd->pipe_in))[WAY_OUT]);
	if (cmd->pipe_out)
		close((*(cmd->pipe_out))[WAY_IN]);
	dup2(tool.save_fd_stdout, STDOUT_FILENO);
	dup2(tool.save_fd_stdin, STDIN_FILENO);
}
