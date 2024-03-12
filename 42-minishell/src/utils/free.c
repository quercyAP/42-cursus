/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:36:55 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/15 10:29:16 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redir(void *content)
{
	t_redir	*node;

	node = content;
	free(node->value);
	free(node);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_cmd(void	*arg)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)arg;
	if (cmd->cmd)
		free(cmd->cmd);
	cmd->lst_param = ft_lstrewind(cmd->lst_param);
	ft_lstclear(&(cmd->lst_param), &free);
	ft_lstclear(&(cmd->lst_redir_in), &free_redir);
	ft_lstclear(&(cmd->lst_redir_out), &free_redir);
	if (cmd->pipe_out)
		free(cmd->pipe_out);
	if (cmd->args)
		free(cmd->args);
	free(cmd);
}

void	free_list(t_list **list)
{
	if (!(*list))
		return ;
	ft_lstclear(list, &free_cmd);
}
