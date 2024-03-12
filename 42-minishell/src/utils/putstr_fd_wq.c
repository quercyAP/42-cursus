/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd_wq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:19:57 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 13:39:41 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	putstr_fd_wq(char *str, int fd)
{
	char	first_c;

	first_c = str[0];
	if (first_c == '\'' || first_c == '\"')
	{
		while (*str)
		{
			if (*str != '\"' && first_c == '\"')
				ft_putchar_fd(*str, fd);
			if (*str != '\'' && first_c == '\'')
				ft_putchar_fd(*str, fd);
			str++;
		}
	}
	else
		ft_putstr_fd(str, fd);
}

void	putstr_fd_wdq(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\"')
			ft_putchar_fd(str[i], fd);
		i++;
	}
}
