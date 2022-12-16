/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:09:57 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/16 14:47:40 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_elem
{
	char	empty;
	char	wall;
	char	item;
	t_list	*lst_item;
	char	exit;
	t_point	*p_exit;
	char	spawn;
	t_point	*p_spwan;
}		t_elem;

char	**parsing(int fd);
int		is_rect(char **map_array);
int		is_close(char **map_array);
void	flood_fill(char **tab, t_point size, t_point cur, t_elem elem);
int		map_len(char **map_array);
t_list	*count_elem(char **map_array, char c);
t_point	*find_elem(char **map_array, char c, t_point *axe);
void	elem_init(t_elem *elem, char **map_array);

#endif