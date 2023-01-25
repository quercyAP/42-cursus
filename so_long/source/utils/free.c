/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:26:22 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/25 14:36:49 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	clear_img(t_game *so)
{
	free_img_tab(so->player->sprite, so);
	free_img(so->player->bullet, so);
	free_img(so->player->lbullet, so);
	free_img(so->energy->img, so);
	free_img(so->gate_anim->img, so);
	mlx_delete_texture(so->void_t);
	mlx_delete_texture(so->gate_t);
	mlx_delete_texture(so->wall_t);
	mlx_delete_image(so->mlx, so->void_i);
	mlx_delete_image(so->mlx, so->gate_i);
	mlx_delete_image(so->mlx, so->wall_i);
}

static void	clear_var(t_game *so)
{
	free(so->player->d_axe);
	free(so->player->u_axe);
	free(so->player->l_axe);
	free(so->player->r_axe);
	free(so->fly_eye->l_axe);
	free(so->fly_eye->r_axe);
	elem_clear(so->elem);
	free_map(so->map);
	free(so->player->coll_pos);
}

void	t_game_clear(t_game *so)
{
	clear_img(so);
	clear_var(so);
	free(so->player);
	free(so->energy);
	free(so->gate_anim);
	free(so->fly_eye);
	free(so);
}
