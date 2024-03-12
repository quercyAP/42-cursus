/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:34:42 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 15:12:52 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cd_home(char *buf, t_cmd *cmd)
{
	char	*ret;

	ret = ft_strdup(get_env(cmd->data->list_env, "HOME"));
	if (!ret)
	{
		free(buf);
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (NULL);
	}
	chdir(ret);
	return (ret);
}

static void	other_case(t_cmd *cmd, char **goto_dir, char *cur_dir)
{
	if (!ft_strncmp((char *)cmd->lst_param->content, "..", 3))
		*goto_dir = cd_back(cur_dir);
	else if (!ft_strncmp((char *)cmd->lst_param->content, "-", 2))
		*goto_dir = cd_moins(get_env(cmd->data->list_env, "OLDPWD"), cmd);
	else
		*goto_dir = getabspath(cur_dir, (char *)cmd->lst_param->content);
}

void	ms_cd(t_cmd *cmd)
{
	char	*cur_dir;
	char	*buf;
	char	*goto_dir;

	buf = ft_calloc(sizeof(char), DIR_BUF);
	if (!buf)
		return ;
	cur_dir = getcwd(buf, DIR_BUF);
	if (!cur_dir)
		perror("minishell: cd");
	goto_dir = NULL;
	if (!cmd->lst_param)
	{
		goto_dir = cd_home(buf, cmd);
		if (!goto_dir)
			return ;
	}
	else
	{
		other_case(cmd, &goto_dir, cur_dir);
		if (chdir(goto_dir) < 0)
			return (cd_error(cur_dir, goto_dir, cmd));
	}
	set_env(cur_dir, goto_dir, cmd);
	(*(cmd->data)).state = EXIT_SUCCESS;
}
