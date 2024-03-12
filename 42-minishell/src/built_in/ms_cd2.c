/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:34:42 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 15:03:36 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cd_back(char *str)
{
	char	*ret;
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	i = ft_strlen(tmp);
	while (i >= 0)
	{
		if (tmp[i] == '/')
		{
			tmp[i] = '\0';
			break ;
		}
		i--;
	}
	ret = ft_strdup(tmp);
	free(tmp);
	return (ret);
}

char	*getabspath(char *current_path, char *r_or_abs_path)
{
	char	*ret;
	char	*tmp;

	if (r_or_abs_path[0] == '/')
		return (ft_strdup(r_or_abs_path));
	else
	{
		tmp = ft_strjoin("/", r_or_abs_path);
		ret = ft_strjoin(current_path, tmp);
		free(tmp);
		return (ret);
	}
}

void	cd_error(char *cur_dir, char *goto_dir, t_cmd *cmd)
{
	ft_putstr_fd("minishell: cd: ", 2);
	perror(goto_dir);
	(*(cmd->data)).state = EXIT_FAILURE;
	free(cur_dir);
	if (goto_dir)
		free(goto_dir);
	return ;
}

void	set_env(char *cur_dir, char *goto_dir, t_cmd *cmd)
{
	t_env	*pwd_env;
	t_env	*old_pwd_env;

	pwd_env = env_is_declare(cmd->data->list_env, "PWD");
	old_pwd_env = env_is_declare(cmd->data->list_env, "OLDPWD");
	free(pwd_env->value);
	free(old_pwd_env->value);
	pwd_env->value = goto_dir;
	old_pwd_env->value = cur_dir;
}

char	*cd_moins(char *old_pwd, t_cmd *cmd)
{
	ft_putstr_fd(old_pwd, 1);
	ft_putstr_fd("\n", 1);
	return (ft_strdup(old_pwd));
}
