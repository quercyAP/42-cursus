/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:28:47 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/03 12:02:43 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	**lst_to_tab(t_list *list)
{
	t_env	**env_tab;
	int		i;

	env_tab = ft_calloc(sizeof(t_env *), ft_lstsize(list) + 1);
	if (!env_tab)
	{
		perror("malloc fail");
		return (NULL);
	}
	i = 0;
	while (list)
	{
		env_tab[i] = list->content;
		i++;
		list = list->next;
	}
	return (env_tab);
}

t_env	**sort_env(t_list *env_list)
{
	t_env	**env_tab;
	int		i;
	int		j;
	t_env	*tmp;

	env_tab = lst_to_tab(env_list);
	if (!env_tab)
		return (NULL);
	i = -1;
	while (env_tab[++i])
	{
		j = i + 1;
		while (env_tab[j])
		{
			if (ft_strncmp(env_tab[j]->name, env_tab[i]->name,
					ft_strlen(env_tab[j]->name)) < 0)
			{
				tmp = env_tab[i];
				env_tab[i] = env_tab[j];
				env_tab[j] = tmp;
			}
			j++;
		}
	}
	return (env_tab);
}
