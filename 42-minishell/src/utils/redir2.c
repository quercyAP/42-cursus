/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:37:11 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/14 15:51:15 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_fd(int *fd, t_redir *redir, t_launch *tool)
{
	if (redir->type == APPEND)
		*fd = open(redir->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (redir->type == REDIR_OUT)
		*fd = open(redir->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd < 0)
	{
		perror(redir->value);
		tool->run = FALSE;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_redir_out(t_cmd *cmd, t_launch *tool)
{
	char	**test;
	t_redir	*redir;
	t_list	*list;

	list = cmd->lst_redir_out;
	while (list)
	{
		redir = (t_redir *)list->content;
		test = ft_split(redir->value, ' ');
		if (test[1])
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(redir->value, 2);
			ft_putstr_fd(": ambiguous redirect\n", 2);
			tool->run = FALSE;
			free_strs(test);
			return (1);
		}
		if (test)
			free_strs(test);
		list = list->next;
	}
	return (0);
}

void	manag_out(t_cmd *cmd, t_launch *tool)
{
	int		fd;
	t_redir	*redir;
	t_list	*list;

	if (check_redir_out(cmd, tool))
		return ;
	list = cmd->lst_redir_out;
	while (list->next)
	{
		redir = (t_redir *)list->content;
		if (redir->type == REDIR_OUT)
		{
			if (check_fd(&fd, redir, tool))
				return ;
			write(fd, "", 0);
			close(fd);
		}
		list = list->next;
	}
	redir = (t_redir *)list->content;
	if (check_fd(&fd, redir, tool))
		return ;
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
