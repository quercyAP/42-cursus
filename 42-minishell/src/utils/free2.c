/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:36:55 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/08 13:40:11 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_envnode(void *content)
{
	t_env	*node;

	node = content;
	free(node->name);
	free(node->value);
	free(node);
}

void	free_envlist(t_list **env)
{
	t_list	*tmp;
	t_env	*node;

	while (*env)
	{
		tmp = (*env)->next;
		free_envnode((*env)->content);
		free(*env);
		*env = tmp;
	}
}
