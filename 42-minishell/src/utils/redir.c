/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:37:11 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/14 15:45:26 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_redir_in(int *fd, t_redir *redir, t_launch *tool, t_cmd *cmd)
{
	*fd = open(redir->value, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(redir->value);
		tool->run = FALSE;
		return (1);
	}
	else
	{
		dup2(*fd, STDIN_FILENO);
		close(*fd);
		return (0);
	}
}

static void	set_delimiter(int *fd, t_redir *redir, t_launch *tool, t_cmd *cmd)
{
	heredoc(redir->value, tool, cmd);
	if (!(tool->run) && !tool->heredoc_killed)
	{
		*fd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		write(*fd, "", 0);
		close(*fd);
		tool->run = TRUE;
	}
	*fd = open(".tmp", O_RDONLY);
	if (*fd < 0)
	{
		perror(redir->value);
		tool->run = FALSE;
	}
	else
	{
		dup2(*fd, STDIN_FILENO);
		close(*fd);
	}
	unlink(".tmp");
}

static int	check_redir_in(int *fd, t_redir *redir, t_launch *tool)
{
	*fd = open(redir->value, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(redir->value);
		tool->run = FALSE;
		return (1);
	}
	close(*fd);
	return (0);
}

static int	manag_in(t_cmd *cmd, t_launch *tool)
{
	int		fd;
	t_redir	*redir;
	t_list	*list;
	char	*tmp_hdoc;
	int		error_found;

	tmp_hdoc = NULL;
	error_found = FALSE;
	list = cmd->lst_redir_in;
	while (list->next)
	{
		redir = (t_redir *)list->content;
		if (redir->type == REDIR_IN && !error_found)
			error_found = check_redir_in(&fd, redir, tool);
		else if (redir->type == DELIMITER)
			heredoc(redir->value, tool, cmd);
		list = list->next;
	}
	redir = (t_redir *)list->content;
	if (redir->type == REDIR_IN && !error_found)
		error_found = set_redir_in(&fd, redir, tool, cmd);
	else if (redir->type == DELIMITER)
		set_delimiter(&fd, redir, tool, cmd);
	return (error_found);
}

void	manag_redir(t_cmd *cmd, t_launch *tool)
{
	int		error_found;

	error_found = FALSE;
	if (cmd->lst_redir_in)
		error_found = manag_in(cmd, tool);
	if (!error_found)
	{
		if (cmd->lst_redir_out)
			manag_out(cmd, tool);
	}
}
