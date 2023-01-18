/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:44:32 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/18 16:41:21 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	elem_init(t_elem *elem, char **map_array)
{
	elem->empty = '0';
	elem->wall = '1';
	elem->exit = 'E';
	elem->lst_exit = count_elem(map_array, 'E');
	elem->item = 'C';
	elem->lst_item = count_elem(map_array, 'C');
	elem->spawn = 'P';
	elem->lst_spawn = count_elem(map_array, 'P');
}

static void	init_sprite(t_game *so, t_player *player, t_item *item)
{
	set_player_sprite("explosion", player->e_len, player->explo, so);
	set_player_sprite("Player-shoot", player->s_len, player->shoot, so);
	set_player_sprite("LPlayer-shoot", player->s_len, player->lshoot, so);
	set_player_sprite("Player-idle", player->p_len, player->idle, so);
	set_player_sprite("LPlayer-idle", player->p_len, player->lidle, so);
	set_player_sprite("LPlayer-run", player->p_len, player->lrun, so);
	set_player_sprite("Player-run", player->p_len, player->run, so);
	set_player_sprite("Bullet", player->b_len, player->bullet, so);
	set_player_sprite("LBullet", player->b_len, player->lbullet, so);
	set_item_sprite("Item-energy", item->i_len, item->img, so);
	set_item_sprite("Force-field", item->i_len, so->gate_anim->img, so);
}

static void	player_init(t_player *player)
{
	player->dir = 1;
	player->s_dir = 1;
	player->jp = 0;
	player->bp = 0;
	player->lbp = 0;
	player->var = 0;
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
}

static void	item_init(t_item *item, int len)
{
	item->type = "Item";
	item->i_len = len;
}

void	game_init(t_game *so, char **map)
{
	so->elem = malloc(sizeof(t_elem));
	so->player = malloc(sizeof(t_player));
	so->energy = malloc(sizeof(t_item));
	so->gate_anim = malloc(sizeof(t_item));
	elem_init(so->elem, map);
	so->win_h = map_len(map) * 64;
	so->win_w = ft_strlen(map[0]) * 64;
	so->mlx = mlx_init(so->win_w, so->win_h, "so", false);
	so->map = map;
	so->nb_pick = 0;
	so->void_t = mlx_load_png("asset/Environment/Void.png");
	so->wall_t = mlx_load_png("asset/Environment/Wall1.png");
	so->gate_t = mlx_load_png("asset/Props/Gate.png");
	so->void_i = mlx_texture_to_image(so->mlx, so->void_t);
	so->wall_i = mlx_texture_to_image(so->mlx, so->wall_t);
	so->gate_i = mlx_texture_to_image(so->mlx, so->gate_t);
	so->gate_i->enabled = false;
	player_init(so->player);
	item_init(so->energy, 5);
	item_init(so->gate_anim, 5);
	init_sprite(so, so ->player, so->energy);
}
