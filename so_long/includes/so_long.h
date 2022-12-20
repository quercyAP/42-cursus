/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:09:57 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/20 17:01:01 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "/Users/glamazer/goinfre/MLX42/include/MLX42/MLX42.h"

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
	t_list	*lst_exit;
	char	spawn;
	t_list	*lst_spawn;
}		t_elem;

char	**parsing(int fd);
void	flood_fill(char **tab, t_point size, int x, int y);
int		map_len(char **map_array);
t_list	*count_elem(char **map_array, char c);
t_point	*find_elem(char **map_array, char c, t_point *axe);
void	elem_init(t_elem *elem, char **map_array);
int		check_error(char **map_array);
int		check_path(char **map_array);
int		list_point_cmp(t_list *list, char **map_array);
void	free_map(char **map_array);
void	lst_clear(t_list **lst);
void	elem_clear(t_elem *elem);

#endif