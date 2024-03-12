/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_envutils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:48:21 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/23 09:50:09 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_envutils(t_env *env)
{
	ft_putstr_fd("=", 1);
	ft_putchar_fd('"', 1);
	ft_putstr_fd(env->value, 1);
	ft_putstr_fd("\"\n", 1);
}
