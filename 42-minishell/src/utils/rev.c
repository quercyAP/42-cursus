/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:40:07 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/23 09:40:08 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rev(t_list *list_cmd, t_data data)
{
	t_cmd	*first;
	t_cmd	*second;

	if (list_cmd)
		first = (t_cmd *)(list_cmd->content);
	if (list_cmd->next)
		second = (t_cmd *)(list_cmd->next->content);
	else
		second = NULL;
	if (first && second && data.quotes == CLOSED && data.error == NONE
		&& !ft_strncmp(first->cmd, "/bin/cat", 9)
		&& !ft_strncmp(second->cmd, "/bin/cat", 9))
		ft_lstiter_rev(data.list_cmd, &launcher);
	else if (data.quotes == CLOSED && data.error == NONE)
		ft_lstiter(data.list_cmd, &launcher);
	else
		ms_perror(NULL, data.error);
}
