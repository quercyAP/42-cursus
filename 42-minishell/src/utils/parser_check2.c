/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:50:11 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/15 15:33:53 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dot_slash(t_cmd **cmd)
{
	if (((*cmd)->cmd)[0] == '.' && !access((*cmd)->cmd, F_OK))
	{
		(*cmd)->cmd_type = OTHER;
		return (1);
	}
	else if (((*cmd)->cmd)[0] == '/' && !access((*cmd)->cmd, F_OK))
	{
		(*cmd)->cmd_type = OTHER;
		return (1);
	}
	return (0);
}
