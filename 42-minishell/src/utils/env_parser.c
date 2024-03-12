/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:30:43 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/15 15:08:38 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_value(t_list **clean_list, t_data *data, char *name, int *i)
{
	char	*value;
	t_list	*node;
	t_env	*env;

	if (!ft_strncmp(name, "$?", 2))
	{
		value = ft_itoa(data->state);
		*i -= (ft_strlen(name) - 2);
	}
	else if (!ft_strncmp(name, "$$", 3))
		value = ft_strdup("$$");
	else if (!ft_strncmp(name, "$", 2))
		value = ft_strdup("$");
	else
	{
		env = env_is_declare(data->list_env, (name + 1));
		if (env)
			value = ft_strdup(env->value);
		else
			value = ft_strdup("");
	}
	free(name);
	node = ft_lstnew(value);
	ft_lstadd_back(clean_list, node);
}

void	add_string(t_list **clean_list, char *str, t_data *data)
{
	t_list	*node;
	char	*tmp;

	if (str[0] == '~' && !str[1])
		node = ft_lstnew(ft_strdup(get_env(data->list_env, "HOME")));
	else if (str[0] == '~' && str[1] && str[1] == '/')
	{
		tmp = ft_strjoin(ft_strdup(get_env(data->list_env, "HOME")), "/");
		tmp = ft_strjoin(tmp, str + 2);
		node = ft_lstnew(tmp);
	}
	else
		node = ft_lstnew(str);
	ft_lstadd_back(clean_list, node);
}

static int	lst_strlen(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i += ft_strlen((char *)list->content);
		list = list->next;
	}
	return (i);
}

char	*list_to_arg(char *clean_str, t_list **clean_list)
{
	int		i;
	int		j;
	char	*cpy;
	t_list	*begin;

	begin = *clean_list;
	if (clean_str)
		free(clean_str);
	clean_str = ft_calloc(sizeof(char), lst_strlen(*clean_list) + 2);
	if (!clean_str)
	{
		perror("malloc fail");
		return (NULL);
	}
	j = -1;
	while (*clean_list)
	{
		i = -1;
		cpy = (*clean_list)->content;
		while (cpy[++i])
			clean_str[++j] = cpy[i];
		(*clean_list) = (*clean_list)->next;
	}
	ft_lstclear(&begin, &free);
	return (clean_str);
}

char	*clean_arg(char *arg, t_data *data)
{
	int			i;
	int			j;
	char		*clean_str;
	t_list		*clean;

	clean = NULL;
	clean_str = NULL;
	i = 0;
	while (arg[i])
	{
		j = 0;
		if (arg[i] == '$')
		{
			while (arg[++i] && char_check(arg[i]))
				j++;
			add_value(&clean, data, ft_substr(arg, i - (j + 1), j + 1), &i);
		}
		else
		{
			i--;
			j = browse_arg2(arg, &i, '$');
			add_string(&clean, ft_substr(arg, i - j, j), data);
		}
	}
	return (list_to_arg(clean_str, &clean));
}
