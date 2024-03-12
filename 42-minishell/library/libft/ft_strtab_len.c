/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:20:18 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/10 13:40:25 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strtab_len(char **str_tab)
{
	int	i;

	i = 0;
	if (!str_tab)
		return (0);
	while (*str_tab)
	{
		str_tab++;
		i++;
	}
	return (i);
}
