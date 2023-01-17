/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:44:32 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/17 21:28:20 by glamazer         ###   ########.fr       */
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

static void	init_sprite(t_game *so)
{
	set_player_sprite("explosion", so->player->e_len, so->player->explo, so);
	set_player_sprite("Player-shoot", so->player->s_len, so->player->shoot, so);
	set_player_sprite("Player-idle", so->player->p_len, so->player->idle, so);
	set_player_sprite("LPlayer-idle", so->player->p_len, so->player->lidle, so);
	set_player_sprite("LPlayer-run", so->player->p_len, so->player->lrun, so);
	set_player_sprite("Player-run", so->player->p_len, so->player->run, so);
	set_player_sprite("Bullet", so->player->b_len, so->player->bullet, so);
	set_player_sprite("LBullet", so->player->b_len, so->player->lbullet, so);
}

static void	player_init(t_player *player)
{
	player->dir = 1;
	player->jp = 0;
	player->sp = 0;
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
}

void	game_init(t_game *so, char **map)
{
	t_elem		*elem;
	t_player	*player;

	elem = malloc(sizeof(t_elem));
	player = malloc(sizeof(t_player));
	elem_init(elem, map);
	so->win_h = map_len(map) * 64;
	so->win_w = ft_strlen(map[0]) * 64;
	so->mlx = mlx_init(so->win_w, so->win_h, "so", false);
	so->map = map;
	so->elem = elem;
	so->player = player;
	so->void_t = mlx_load_png("asset/Environment/Void.png");
	so->wall_t = mlx_load_png("asset/Environment/Wall1.png");
	so->gate_t = mlx_load_png("asset/Props/Gate.png");
	so->void_i = mlx_texture_to_image(so->mlx, so->void_t);
	so->wall_i = mlx_texture_to_image(so->mlx, so->wall_t);
	so->gate_i = mlx_texture_to_image(so->mlx, so->gate_t);
	player_init(so->player);
	init_sprite(so);
}
