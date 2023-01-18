/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:02 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/18 17:18:32 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_point	*player_dcoll(void *param)
{
	t_point	*p_axe;
	t_game	*so;
	int		of;
	int		i;

	of = 64;
	so = param;
	p_axe = malloc(sizeof(t_point));
	p_axe->y = (so->player->idle[0]->instances->y
			+ of + so->player->var) / of;
	i = of - 5;
	while (i > 0)
	{
		p_axe->x = (so->player->idle[0]->instances->x + i) / of;
		if (so->map[p_axe->y][p_axe->x] == '1')
		{
			free(p_axe);
			return (NULL);
		}
		else if (so->map[p_axe->y][p_axe->x] == 'C'
			|| so->map[p_axe->y][p_axe->x] == 'E')
			return (p_axe);
		i--;
	}
	return (&(t_point){0, 0});
}

t_point	*player_lcoll(void *param)
{
	t_point	*p_axe;
	t_game	*so;
	int		of;
	int		i;

	of = 64;
	so = param;
	p_axe = malloc(sizeof(t_point));
	p_axe->x = (so->player->idle[0]->instances->x - 5) / of;
	i = 0;
	while (i < of - 1)
	{
		p_axe->y = (so->player->idle[0]->instances->y + i) / of;
		if (so->map[p_axe->y][p_axe->x] == '1')
		{
			free(p_axe);
			return (NULL);
		}
		else if (so->map[p_axe->y][p_axe->x] == 'C'
			|| so->map[p_axe->y][p_axe->x] == 'E')
			return (p_axe);
		i++;
	}
	return (&(t_point){0, 0});
}

t_point	*player_rcoll(void *param)
{
	t_point	*p_axe;
	t_game	*so;
	int		of;
	int		i;

	of = 64;
	so = param;
	p_axe = malloc(sizeof(t_point));
	p_axe->x = (so->player->idle[0]->instances->x + of) / of;
	i = 0;
	while (i < of - 1)
	{
		p_axe->y = (so->player->idle[0]->instances->y + i) / of;
		if (so->map[p_axe->y][p_axe->x] == '1')
		{
			free(p_axe);
			return (NULL);
		}
		else if (so->map[p_axe->y][p_axe->x] == 'C'
			|| so->map[p_axe->y][p_axe->x] == 'E')
			return (p_axe);
		i++;
	}
	return (&(t_point){0, 0});
}

t_point	*player_ucoll(void *param)
{
	t_point	*p_axe;
	t_game	*so;
	int		of;
	int		i;

	of = 64;
	so = param;
	p_axe = malloc(sizeof(t_point));
	p_axe->y = (so->player->idle[0]->instances->y - 5) / of;
	i = of - 5;
	while (i > 0)
	{
		p_axe->x = (so->player->idle[0]->instances->x + i) / of;
		if (so->map[p_axe->y][p_axe->x] == '1')
		{
			free(p_axe);
			return (NULL);
		}
		else if (so->map[p_axe->y][p_axe->x] == 'C'
			|| so->map[p_axe->y][p_axe->x] == 'E')
			return (p_axe);
		i--;
	}
	return (&(t_point){0, 0});
}
