/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:08:47 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/06 12:10:12 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_main(t_data *data)
{
	rl_catch_signals = 1;
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	free_envlist(&(data->list_env));
	free_list(&(data->list_cmd));
	exit(data->state % 255);
}
