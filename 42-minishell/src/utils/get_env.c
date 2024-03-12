/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:02:52 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/09 15:56:58 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_is_declare(t_list *env_list, char *name)
{
	t_env	*node;
	t_list	*list;

	list = env_list;
	while (list)
	{
		node = list->content;
		if (!ft_strncmp(node->name, name, ft_strlen(name) + 1))
			return (node);
		list = list->next;
	}
	list = env_list;
	return (NULL);
}

char	*get_env(t_list *list_env, char *var)
{
	t_env	*node;
	char	*ret;
	t_list	*tmp;

	if (!var)
		return (NULL);
	tmp = list_env;
	while (tmp)
	{
		node = tmp->content;
		if (!ft_strncmp(var, node->name, ft_strlen(var) + 1))
		{
			ret = node->value;
			return (ret);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
