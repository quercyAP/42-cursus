/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:41:06 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/14 12:26:02 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	display_fail(t_cmd *cmd, char *arg)
{
	ft_putstr_fd("minishell: unset: \" ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(" \" : not a valid identifier\n", 2);
	cmd->data->state = EXIT_FAILURE;
}

static void	del_node(t_list *list, t_env *env)
{
	t_env	*cmp;

	while (list)
	{
		cmp = list->content;
		if (!ft_strncmp(env->name, cmp->name, ft_strlen(cmp->name) + 1))
		{
			ft_lstdelone(list, &free_envnode);
			break ;
		}
		list = list->next;
	}
}

static int	check_enverror(char *arg)
{
	int	i;

	i = -1;
	if (ft_isdigit(arg[0]))
		return (0);
	while (arg[++i])
	{
		if (arg[i] == '_')
			continue ;
		if (!ft_isalnum(arg[i]))
			return (0);
	}
	return (1);
}

void	ms_unset(t_cmd *cmd)
{
	int		i;
	t_env	*env;
	t_list	*list;

	cmd->data->state = EXIT_SUCCESS;
	i = 0;
	while (cmd->args[++i])
	{
		if (check_enverror(cmd->args[i]))
		{
			list = cmd->data->list_env;
			env = env_is_declare(cmd->data->list_env, cmd->args[i]);
			if (env)
				del_node(list, env);
		}
		else
			display_fail(cmd, cmd->args[i]);
	}
}
