/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:09:57 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/12 14:28:21 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/Users/glamazer/goinfre/MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
// # include "/home/guigui/MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_elem
{
	char			empty;
	char			wall;
	char			item;
	t_list			*lst_item;
	char			exit;
	t_list			*lst_exit;
	char			spawn;
	t_list			*lst_spawn;
}					t_elem;

typedef struct s_game
{
	mlx_t			*mlx;
	int				win_w;
	int				win_h;
	char			**map;
	int				ip;
	int				lip;
	int				rip;
	int				rlip;
	int				dir;
	int				jp;
	int				p_len;
	int				j_len;
	int				move_state;
	int				jump_state;
	t_elem			*elem;
	mlx_texture_t	*void_t;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*player_idle_t[6];
	mlx_texture_t	*lplayer_idle_t[6];
	mlx_texture_t	*player_run_t[6];
	mlx_texture_t	*lplayer_run_t[6];
	mlx_texture_t	*player_jet_t[4];
	mlx_texture_t	*gate_t;
	mlx_image_t		*void_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*player_idle_i[6];
	mlx_image_t		*player_run_i[6];
	mlx_image_t		*lplayer_run_i[6];
	mlx_image_t		*lplayer_idle_i[6];
	mlx_image_t		*player_jet_i[4];
	mlx_image_t		*gate_i;
}					t_game;

// check map
char				**parsing(int fd);
void				flood_fill(char **tab, t_point size, int x, int y);
int					check_error(char **map_array);
int					check_path(char **map_array);
int					list_point_cmp(t_list *list, char **map_array);
// clean up
void				free_map(char **map_array);
void				t_game_clear(t_game *so_long);
void				lst_clear(t_list **lst);
void				elem_clear(t_elem *elem);
//	init
void				elem_init(t_elem *elem, char **map_array);
void				game_init(t_game *so_long, char **map);
void				set_sprite(char *sprite_name, int nb_sprite, char *type,
						t_game *so_long);
// utils
int					map_len(char **map_array);
char				**map_dup(char **map_array);
t_list				*count_elem(char **map_array, char c);
t_point				*find_elem(char **map_array, char c, t_point *axe);
void				draw_map(t_game *so_long);
void				draw_img(t_game *so, t_point of,
						mlx_image_t **img, int len);
// collision
int					player_dcoll(t_game *so_long, int vof);
int					player_lcoll(t_game *so_long);
int					player_rcoll(t_game *so_long);
int					player_ucoll(t_game *so_long);
// animator
void				player_idle(t_game *so_long);
void				lplayer_idle(t_game *so_long);
void				player_jet(t_game *so_long);
void				del_img(mlx_image_t **img, int len);
void				lplayer_run(t_game *so_long);
void				player_run(t_game *so_long);
// hook
void				move_hook(void *param);
void				player_anim(void *so);
// player movement
void				player_move(t_game *so, float nb, char axe);
void				player_jump(t_game *so_long);
void				gravity(t_game *so_long);

#endif