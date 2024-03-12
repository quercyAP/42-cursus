/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:50:30 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/23 09:50:32 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	display_fail(t_cmd *cmd, char *arg)
{
	ft_putstr_fd("minishell: export: \" ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(" \" : not a valid identifier\n", 2);
	cmd->data->state = EXIT_FAILURE;
}

static void	display_envtab(t_env **env_tab)
{
	int	i;

	i = 0;
	if (!env_tab)
		return ;
	while (env_tab[i])
	{
		if (!ft_strncmp(env_tab[i]->name, "_", 2))
		{
			i++;
			continue ;
		}
		ft_putstr_fd("declare -x ", 1);
		putstr_fd_wq(env_tab[i]->name, 1);
		if (env_tab[i]->value[0])
			display_envutils(env_tab[i]);
		else if (env_tab[i]->display_env)
			ft_putstr_fd("=\"\"\n", 1);
		else
			ft_putstr_fd("\n", 1);
		i++;
	}
}

static void	export_utils(t_cmd *cmd, char *arg)
{
	t_env	*env;
	char	*value;
	char	*name;
	int		i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	name = ft_substr(arg, 0, i);
	env = env_is_declare(cmd->data->list_env, name);
	if (env)
	{
		free(env->value);
		value = (arg + ft_strlen(name));
		if (value && value[0] == '=')
			value = (arg + ft_strlen(name) + 1);
		env->value = ft_strdup(value);
		if (arg[i] && arg[i] == '=')
			env->display_env = 1;
	}
	else
		set_envnode(arg, &cmd->data->list_env);
	free(name);
}

static int	check_enverror(char *arg)
{
	int	i;

	i = -1;
	if (arg && !arg[0])
		return (0);
	if (arg[i + 1] == '=' || ft_isdigit(arg[0]))
		return (0);
	while (arg[++i] && arg[i] != '=')
	{
		if (arg[i] == '_')
			continue ;
		if (!ft_isalnum(arg[i]))
			return (0);
	}
	return (1);
}

void	ms_export(t_cmd *cmd)
{
	int		i;
	t_env	**env_tab;

	env_tab = sort_env(cmd->data->list_env);
	cmd->data->state = EXIT_SUCCESS;
	if (ft_strtab_len(cmd->args) == 1)
		display_envtab(env_tab);
	else
	{
		i = 0;
		while (cmd->args[++i])
		{
			if (!check_enverror(cmd->args[i]))
			{
				display_fail(cmd, cmd->args[i]);
				continue ;
			}
			export_utils(cmd, cmd->args[i]);
		}
	}
	free(env_tab);
}
