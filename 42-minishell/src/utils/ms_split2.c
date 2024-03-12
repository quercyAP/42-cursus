/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 13:25:25 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_d_quotes(char **str, t_data *data)
{
	if (**str == '\"' && data->d_quotes == CLOSED && data->s_quotes == CLOSED)
	{
		data->quotes = OPEN;
		data->d_quotes = OPEN;
	}
	else if (**str == '\"' && data->d_quotes == OPEN)
	{
		data->quotes = CLOSED;
		data->d_quotes = CLOSED;
	}
}

void	check_s_quotes(char **str, t_data *data)
{
	if (**str == '\'' && data->s_quotes == CLOSED && data->d_quotes == CLOSED)
	{
		data->quotes = OPEN;
		data->s_quotes = OPEN;
	}
	else if (**str == '\'' && data->s_quotes == OPEN)
	{
		data->quotes = CLOSED;
		data->s_quotes = CLOSED;
	}
}
