/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:08:32 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/25 20:04:32 by glamazer         ###   ########.fr       */
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
	elem->mob = 'M';
	elem->lst_mob = count_elem(map_array, 'M');
}

void	init_sprite(t_game *so, t_player *player, t_item *item, t_mob *mob)
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
	set_mob_sprite("Fly-eye", mob->i_len, so->fly_eye->idle, so);
}
