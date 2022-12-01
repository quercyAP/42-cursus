/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:24:08 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/17 12:52:00 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunbr(unsigned int n, int *nb)
{
	if (n >= 10)
	{
		if (ft_printunbr(n / 10, nb) < 0)
			return (-1);
		if (ft_printunbr(n % 10, nb) < 0)
			return (-1);
	}
	else if (ft_printchar(n + 48, nb) < 0)
		return (-1);
	return (0);
}
