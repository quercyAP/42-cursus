/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:44:32 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/12 14:28:41 by glamazer         ###   ########.fr       */
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

static void	init_sprite(t_game *so_long)
{
	set_sprite("Player-idle", so_long->p_len, "Player", so_long);
	set_sprite("LPlayer-idle", so_long->p_len, "Player", so_long);
	set_sprite("LPlayer-run", so_long->p_len, "Player", so_long);
	set_sprite("Player-run", so_long->p_len, "Player", so_long);
	set_sprite("Player-jet", so_long->j_len, "Player", so_long);
}

void	game_init(t_game *so_long, char **map)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	elem_init(elem, map);
	so_long->win_h = map_len(map) * 64;
	so_long->win_w = ft_strlen(map[0]) * 64;
	so_long->mlx = mlx_init(so_long->win_w, so_long->win_h, "so_long", true);
	so_long->map = map;
	so_long->ip = 0;
	so_long->lip = 0;
	so_long->rip = 0;
	so_long->dir = 1;
	so_long->rlip = 0;
	so_long->jp = 0;
	so_long->p_len = 6;
	so_long->j_len = 4;
	so_long->move_state = 0;
	so_long->jump_state = 0;
	so_long->elem = elem;
	so_long->void_t = mlx_load_png("asset/Environment/Void.png");
	so_long->wall_t = mlx_load_png("asset/Environment/Wall1.png");
	so_long->gate_t = mlx_load_png("asset/Props/Gate.png");
	so_long->void_i = mlx_texture_to_image(so_long->mlx, so_long->void_t);
	so_long->wall_i = mlx_texture_to_image(so_long->mlx, so_long->wall_t);
	so_long->gate_i = mlx_texture_to_image(so_long->mlx, so_long->gate_t);
	init_sprite(so_long);
}
