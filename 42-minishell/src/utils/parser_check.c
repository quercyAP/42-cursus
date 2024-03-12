/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:50:11 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/15 15:34:38 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_built_in(t_cmd **cmd)
{
	if (!(ft_strncmp((*cmd)->cmd, "echo", 5)))
		(*cmd)->cmd_type = B_ECHO;
	else if (!(ft_strncmp((*cmd)->cmd, "cd", 3)))
		(*cmd)->cmd_type = B_CD;
	else if (!(ft_strncmp((*cmd)->cmd, "pwd", 4)))
		(*cmd)->cmd_type = B_PWD;
	else if (!(ft_strncmp((*cmd)->cmd, "export", 7)))
		(*cmd)->cmd_type = B_EXPORT;
	else if (!(ft_strncmp((*cmd)->cmd, "unset", 6)))
		(*cmd)->cmd_type = B_UNSET;
	else if (!(ft_strncmp((*cmd)->cmd, "env", 4)))
		(*cmd)->cmd_type = B_ENV;
	else if (!(ft_strncmp((*cmd)->cmd, "exit", 5)))
		(*cmd)->cmd_type = B_EXIT;
}

static void	end_free(char **path_tab, char *tmp)
{
	free(tmp);
	free_strs(path_tab);
}

static int	found(t_cmd **cmd, char **path_tab, char *path, char *tmp)
{
	free((*cmd)->cmd);
	(*cmd)->cmd = path;
	(*cmd)->cmd_type = OTHER;
	end_free(path_tab, tmp);
	return (EXIT_SUCCESS);
}

static int	check_other(t_cmd **cmd, char **path_tab, char *path, char *tmp)
{
	int	i;

	if (check_dot_slash(cmd))
		return (EXIT_SUCCESS);
	if (access((*cmd)->cmd, F_OK) && ft_strchr((*cmd)->cmd, '/'))
		return (EXIT_FAILURE);
	(*cmd)->cmd = cmd_parser((*cmd)->cmd);
	path_tab = ft_split(get_env((*cmd)->data->list_env, "PATH"), ':');
	if (!path_tab)
		return (EXIT_FAILURE);
	tmp = ft_strjoin("/", (*cmd)->cmd);
	i = -1;
	while (path_tab[++i])
	{
		path = ft_strjoin(path_tab[i], tmp);
		if (!access(path, F_OK))
			return (found(cmd, path_tab, path, tmp));
		free(path);
	}
	end_free(path_tab, tmp);
	return (EXIT_FAILURE);
}

int	check_cmd_path(t_cmd **cmd)
{
	check_built_in(cmd);
	if (!(*cmd)->cmd_type && check_other(cmd, NULL, NULL, NULL))
	{
		(*cmd)->cmd_type = UNKNOWN;
		return (0);
	}
	if (!(*cmd)->cmd_type)
	{
		(*cmd)->cmd_type = UNKNOWN;
		return (0);
	}
	else
		return (1);
}
