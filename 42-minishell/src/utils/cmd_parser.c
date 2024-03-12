/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:50:26 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/14 13:00:00 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_parser(char *cmd)
{
	char	*ret;
	char	**tmp;

	tmp = ft_split(cmd, '/');
	if (ft_strtab_len(tmp) > 1)
		ret = ft_strdup(tmp[ft_strtab_len(tmp) - 1]);
	else
		ret = ft_strdup(tmp[0]);
	free(cmd);
	free_strs(tmp);
	return (ret);
}
