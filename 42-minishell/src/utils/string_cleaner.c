/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:46:02 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/02 12:40:16 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "string_cleaner_utils.h"

void	make_char_node(char **dirty, t_char **previous, t_char **current)
{
	(*current) = ft_calloc(sizeof(t_char), 1);
	if (!(*current))
		return ;
	(*previous)->next = (*current);
	(*current)->prev = (*previous);
	(*previous) = (*current);
	(*current)->c = **dirty;
	(*dirty)++;
}

static t_char	*char_list_maker(char *dirty, t_char *previous, t_char *current)
{
	t_char	*begin;
	char	*dirty_save;

	dirty_save = dirty;
	if (!dirty || !(*dirty))
		return (NULL);
	begin = ft_calloc(sizeof(t_char), 1);
	if (!begin)
		return (NULL);
	begin->c = *dirty;
	dirty++;
	previous = begin;
	while (*dirty)
	{
		make_char_node(&dirty, &previous, &current);
	}
	current = ft_calloc(sizeof(t_char), 1);
	if (!current)
		return (NULL);
	previous->next = current;
	current->prev = previous;
	previous = current;
	current->c = '\0';
	free(dirty_save);
	return (begin);
}

static char	*str_from_list(t_char *begin)
{
	t_char	*begin_save;
	int		i;
	char	*str_ret;

	if (!begin)
		return (NULL);
	i = 0;
	begin_save = begin;
	while (begin)
	{
		i++;
		begin = begin->next;
	}
	begin = begin_save;
	str_ret = ft_calloc(sizeof(char), (i + 1));
	if (!str_ret)
		return (NULL);
	i = 0;
	while (begin)
	{
		str_ret[i] = begin->c;
		i++;
		begin = begin->next;
	}
	return (str_ret);
}

static void	free_lst_char(t_char **begin)
{
	t_char	*tmp;

	while (*begin)
	{
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
}

char	*string_cleaner(char *dirty, t_data data)
{
	char	*clean;
	t_char	*begin;

	if (!dirty)
		return (NULL);
	if (data.debug)
		printf("dirty -> (%s)\n", dirty);
	begin = char_list_maker(dirty, NULL, NULL);
	if (!begin)
		return (NULL);
	space_inserter(&begin);
	clean = str_from_list(begin);
	free_lst_char(&begin);
	if (!clean)
		return (NULL);
	if (data.debug)
		printf("clean -> (%s)\n", clean);
	return (clean);
}
