/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:06:28 by tdechand          #+#    #+#             */
/*   Updated: 2023/02/20 13:22:44 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_pwd(t_cmd *cmd)
{
	char	*cur_dir;
	char	*buf;

	buf = ft_calloc(sizeof(char), DIR_BUF);
	if (!buf)
		return ;
	cur_dir = getcwd(buf, DIR_BUF);
	if (!cur_dir)
		perror("cd");
	ft_putstr_fd(cur_dir, 1);
	ft_putstr_fd("\n", 1);
	free(cur_dir);
	(*(cmd->data)).state = EXIT_SUCCESS;
}
