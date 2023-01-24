/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:44:32 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/24 13:53:52 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	player_init(t_player *player)
{
	player->dir = 1;
	player->s_dir = 1;
	player->jp = 0;
	player->step = 0;
	player->bp = 0;
	player->lbp = 0;
	player->var = 5;
	player->ammo = 11;
	player->p_len = 6;
	player->s_len = 3;
	player->e_len = 9;
	player->b_len = 4;
	player->sprite_len = 0;
	player->move_state = 0;
	player->jump_state = 0;
	player->shoot_state = 0;
	player->type = "Player";
	player->coll_pos = malloc(sizeof(t_point) * 4);
	player->d_axe = malloc(sizeof(t_point));
	player->u_axe = malloc(sizeof(t_point));
	player->r_axe = malloc(sizeof(t_point));
	player->l_axe = malloc(sizeof(t_point));
}

static void	mob_init(t_mob *mob)
{
	mob->type = "Mob";
	mob->i_len = 4;
}

static void	item_init(t_item *item, int len)
{
	item->type = "Item";
	item->i_len = len;
}

static void	var_init(t_game *so, char **map)
{
	so->finish = false;
	so->nb_pick = 0;
	so->map = map;
	so->step = "Number of steps";
	so->void_t = mlx_load_png("asset/Environment/Void.png");
	so->wall_t = mlx_load_png("asset/Environment/Wall1.png");
	so->gate_t = mlx_load_png("asset/Props/Gate.png");
	so->void_i = mlx_texture_to_image(so->mlx, so->void_t);
	so->wall_i = mlx_texture_to_image(so->mlx, so->wall_t);
	so->gate_i = mlx_texture_to_image(so->mlx, so->gate_t);
	so->gate_i->enabled = false;
}

void	game_init(t_game *so, char **map)
{
	so->elem = malloc(sizeof(t_elem));
	so->player = malloc(sizeof(t_player));
	so->energy = malloc(sizeof(t_item));
	so->gate_anim = malloc(sizeof(t_item));
	so->fly_eye = malloc(sizeof(t_mob));
	elem_init(so->elem, map);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	so->win_h = map_len(map) * 64;
	so->win_w = ft_strlen(map[0]) * 64;
	so->mlx = mlx_init(so->win_w, so->win_h, "so", true);
	var_init(so, map);
	player_init(so->player);
	item_init(so->energy, 5);
	item_init(so->gate_anim, 5);
	mob_init(so->fly_eye);
	init_sprite(so, so ->player, so->energy, so->fly_eye);
}
