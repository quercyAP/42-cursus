/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_envlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:29:51 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/23 09:30:06 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_envnode(char *env, t_list **list_env)
{
	t_env	*env_node;
	t_list	*node;
	int		i;

	env_node = malloc(sizeof(t_env));
	env_node->display_env = 0;
	if (!env_node)
	{
		perror("malloc fail");
		return ;
	}
	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	if (env[i] == '=')
		env_node->display_env = 1;
	env_node->name = ft_substr(env, 0, i);
	env_node->value = ft_substr(env, i + 1, ft_strlen(env) - i);
	node = ft_lstnew(env_node);
	ft_lstadd_back(list_env, node);
}

t_list	*set_listenv(char **penv)
{
	t_list	*start;
	int		i;

	start = NULL;
	if (penv)
	{
		i = 0;
		while (penv[i])
		{
			set_envnode(penv[i], &start);
			i++;
		}
	}
	return (start);
}
