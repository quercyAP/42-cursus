/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_step.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:41:18 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/25 12:04:53 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_step(t_game *so)
{
	int			curr;
	static int	prev;

	curr = so->player->step;
	if (curr != prev)
	{
		prev = so->player->step;
		so->itoa = ft_itoa(so->player->step);
		so->step = ft_strjoin("Number of steps : ", so->itoa);
		if (so->bonus)
		{
			mlx_delete_image(so->mlx, so->step_str);
			so->step_str = mlx_put_string(so->mlx, so->step, 0, 0);
		}
		else
		{
			ft_putstr_fd(so->step, 1);
			write(1, "\n", 1);
		}
		free(so->itoa);
		free(so->step);
	}
}

void	end_msg(bool win, t_game *so)
{
	if (win)
	{
		ft_putstr_fd("CONGRATULATION !!!\nYou won the game with ", 1);
		ft_putnbr_fd(so->player->step, 1);
		write(1, " steps\n", 7);
	}
	else
		ft_putstr_fd("LOOSER !!!\n", 1);
}
