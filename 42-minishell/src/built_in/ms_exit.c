/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:17:37 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/14 14:26:11 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric(char *arg)
{
	char	*local;

	local = arg;
	if (*local == '-' || *local == '+')
		local++;
	while (*local)
	{
		if (!ft_isdigit(*local))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			return (0);
		}
		local++;
	}
	return (1);
}

static int	param_check(t_cmd *cmd)
{
	int	long_overflown;

	long_overflown = FALSE;
	if (cmd->lst_param && cmd->lst_param->next)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	if (cmd->lst_param && is_numeric((char *)cmd->lst_param->content))
	{
		ft_atoll((char *)cmd->lst_param->content, &long_overflown);
		if (long_overflown)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd((char *)cmd->lst_param->content, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
		}
		else
		{
			cmd->data->state = ft_atoi((char *)cmd->lst_param->content);
			return (0);
		}
	}
	cmd->data->state = 255;
	return (0);
}

void	ms_exit(t_cmd *cmd)
{
	int	ret;

	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (param_check(cmd))
		return ;
	rl_catch_signals = 1;
	ret = cmd->data->state % 256;
	free_envlist(&(cmd->data->list_env));
	free_list(&(cmd->data->list_cmd));
	exit(ret);
}
