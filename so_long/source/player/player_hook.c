/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:56:20 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/19 09:33:13 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	fire(t_game *so, mlx_image_t **bullet, int *j)
{
	int	i;

	i = 0;
	while (i < so->player->b_len)
	{
		bullet[i]->instances[*j].enabled = true;
		i++;
	}
	*j = (*j + 1) % so->player->ammo;
}

static void	player_anim(t_game *so)
{
	int		len;

	len = so->player->sprite_len;
	if (!so->player->dir && !so->player->move_state)
		set_anim(so->player, lplayer_idle, so->player->sprite, len);
	else if (so->player->dir && !so->player->move_state)
		set_anim(so->player, player_idle, so->player->sprite, len);
	if (!so->player->dir && so->player->move_state
		&& !so->player->shoot_state)
		set_anim(so->player, lplayer_run, so->player->sprite, len);
	else if (so->player->dir && so->player->move_state
		&& !so->player->shoot_state)
		set_anim(so->player, player_run, so->player->sprite, len);
	if (so->player->shoot_state && so->player->s_dir)
		set_anim(so->player, player_shoot, so->player->sprite, len);
	else if (so->player->shoot_state && !so->player->s_dir)
		set_anim(so->player, lplayer_shoot, so->player->sprite, len);
	if (so->player->jump_state)
		player_jet(so->player);
	else if (!so->player->jump_state && player_dcoll(so))
		player_jet1(so->player);
}

static void	move_hook(t_game *so)
{
	gravity(so);
	if (mlx_is_key_down(so->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(so->mlx);
	if (mlx_is_key_down(so->mlx, MLX_KEY_W))
		player_jump(so);
	if (mlx_is_key_down(so->mlx, MLX_KEY_A) && player_lcoll(so))
	{
		so->player->dir = 0;
		so->player->step++;
		player_move(so->player, -5, 'x');
	}
	else if (mlx_is_key_down(so->mlx, MLX_KEY_D) && player_rcoll(so))
	{
		so->player->dir = 1;
		so->player->step++;
		player_move(so->player, 5, 'x');
	}
	else
		so->player->move_state = 0;
}

void	player_hook(void *param)
{
	t_game		*so;
	int			curr;
	static int	prev;

	so = param;
	move_hook(so);
	player_anim(so);
	del_img(so->player->bullet);
	bullet_anim(so->player);
	del_img(so->player->lbullet);
	lbullet_anim(so->player);
	bullet_routine(so);
	curr = so->player->step;
	if (curr != prev)
	{
		prev = so->player->step;
		mlx_delete_image(so->mlx, so->step_str);
		so->step = ft_strjoin("Number of steps : ", ft_itoa(so->player->step));
		ft_putstr_fd(so->step, 1);
		write(1, "\n", 1);
		so->step_str = mlx_put_string(so->mlx, so->step, 0, 0);
	}
}

void	bullet_shoot(mlx_key_data_t data, void *param)
{
	t_game	*so;

	so = param;
	if (data.key == MLX_KEY_RIGHT)
	{
		so->player->shoot_state = 1;
		so->player->s_dir = 1;
		fire(so, so->player->bullet, &so->player->bp);
	}
	else if (data.key == MLX_KEY_LEFT)
	{
		so->player->shoot_state = 1;
		so->player->s_dir = 0;
		fire(so, so->player->lbullet, &so->player->lbp);
	}
}
