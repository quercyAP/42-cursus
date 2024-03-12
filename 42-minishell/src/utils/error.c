/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:38:56 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 11:28:50 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_str_error(enum e_error error)
{
	if (error == TOKEN_ERROR)
		return (ft_strdup("syntax error near unexpected token"));
	else if (error == NOT_FOUND_ERROR)
		return (ft_strdup("not found"));
	else if (error == QUOTES_OPENED_ERROR)
		return (ft_strdup("quotes are not closed"));
	else
		return (NULL);
}

void	kill_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ms_perror(char *msg, enum e_error error)
{
	char	*str_error;

	if (error)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		if (msg)
		{
			ft_putstr_fd(msg, STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
		}
		str_error = get_str_error(error);
		ft_putstr_fd(str_error, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		if (str_error)
			free(str_error);
	}
}
