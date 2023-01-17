/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:09:57 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/17 21:28:47 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "/Users/glamazer/goinfre/MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "/home/guigui/MLX42/include/MLX42/MLX42.h"

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

typedef struct s_player
{
	int				jp;
	int				sp;
	int				ammo;
	int				b_spawn[11];
	int				p_len;
	int				b_len;
	int				e_len;
	int				s_len;
	int				dir;
	int				move_state;
	int				jump_state;
	int				shoot_state;
	int				sprite_len;
	char			*type;
	mlx_image_t		**sprite[6];
	mlx_image_t		*idle[7];
	mlx_image_t		*lidle[7];
	mlx_image_t		*run[7];
	mlx_image_t		*lrun[7];
	mlx_image_t		*explo[10];
	mlx_image_t		*shoot[4];
	mlx_image_t		*bullet[5];
	mlx_image_t		*lbullet[5];
}					t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	int				win_w;
	int				win_h;
	char			**map;
	t_elem			*elem;
	mlx_texture_t	*void_t;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*gate_t;
	mlx_image_t		*void_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*gate_i;
	t_player		*player;
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
void				set_player_sprite(char *sprite_name, int nb_sprite,
						mlx_image_t **img, t_game *so_long);
// utils
int					map_len(char **map_array);
char				**map_dup(char **map_array);
t_list				*count_elem(char **map_array, char c);
t_point				*find_elem(char **map_array, char c, t_point *axe);
void				draw_map(t_game *so_long);
void				draw_img(t_game *so, t_point of,
						mlx_image_t **img, int len);
void				player_draw(t_game *so);
int					sprite_len(mlx_image_t **array);
void				del_img(mlx_image_t **img);
void				set_anim(t_player *player, void (*anim)(t_player *),
						mlx_image_t ***img, int len);
// collision
int					player_dcoll(t_game *so_long, int vof);
int					player_lcoll(t_game *so_long);
int					player_rcoll(t_game *so_long);
int					player_ucoll(t_game *so_long);
// player anim
void				player_idle(t_player *player);
void				lplayer_idle(t_player *player);
void				player_jet(t_player *player);
void				lplayer_run(t_player *player);
void				player_run(t_player *player);
void				player_jet1(t_player *player);
void				player_shoot(t_player *player);
void				bullet_anim(t_player *player);
void				bullet_shoot(mlx_key_data_t data, void *param);
void				bullet_routine(void *para);
// hook
void				player_hook(void *param);
// player movement
void				player_move(t_player *player, float nb, char axe);
void				player_jump(t_game *so_long);
void				gravity(t_game *so_long);

#endif