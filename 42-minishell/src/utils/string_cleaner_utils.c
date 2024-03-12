/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_cleaner_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:46:02 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/06 10:04:14 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	put_space_before(t_char **current)
{
	t_char	*space;

	space = ft_calloc(sizeof(t_char), 1);
	if (!space)
		return ;
	space->c = ' ';
	(*current)->prev->next = space;
	space->prev = (*current)->prev;
	space->next = (*current);
	(*current)->prev = space;
}

static void	put_space_after(t_char **current)
{
	t_char	*space;

	space = ft_calloc(sizeof(t_char), 1);
	if (!space)
		return ;
	space->c = ' ';
	space->prev = *current;
	space->next = (*current)->next;
	(*current)->next->prev = space;
	(*current)->next = space;
}

int	char_ok(int c, int x)
{
	if (c == x || c == ' ')
		return (0);
	if ((c >= 32 && c <= 126))
		return (1);
	else
		return (0);
}

void	find_and_space(char c, t_char **cur)
{
	if (!(*cur)->prev && (*cur)->next
		&& (*cur)->c == c && char_ok((*cur)->next->c, (*cur)->c))
		put_space_after(cur);
	if ((*cur)->prev && (*cur)->next
		&& !((*cur)->next->c == c)
		&& (*cur)->c == c && char_ok((*cur)->prev->c, (*cur)->c))
		put_space_before(cur);
	if ((*cur)->prev && (*cur)->next
		&& !((*cur)->prev->c == c)
		&& (*cur)->c == c && char_ok((*cur)->next->c, (*cur)->c))
		put_space_after(cur);
	if ((*cur)->prev && (*cur)->next
		&& ((*cur)->next->c == c)
		&& (*cur)->c == c && char_ok((*cur)->prev->c, (*cur)->c))
		put_space_before(cur);
	if ((*cur)->prev && (*cur)->next
		&& ((*cur)->prev->c == c)
		&& (*cur)->c == c && ft_isprint((*cur)->next->c))
		put_space_after(cur);
}

void	space_inserter(t_char **begin)
{
	t_char	**current;
	t_char	*begin_save;

	current = begin;
	begin_save = *begin;
	while (*current)
	{
		find_and_space('|', current);
		find_and_space('>', current);
		find_and_space('<', current);
		find_and_space('&', current);
		find_and_space(';', current);
		*current = (*current)->next;
	}
	*begin = begin_save;
}
