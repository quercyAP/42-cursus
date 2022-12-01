/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:59:52 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/17 12:01:03 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n, int *nb)
{
	long int		nub;

	nub = n;
	if (nub < 0)
	{
		if (ft_printchar('-', nb) < 0)
			return (-1);
		nub *= -1;
	}
	if (nub >= 10)
	{
		if (ft_printnbr(nub / 10, nb) < 0)
			return (-1);
		if (ft_printnbr(nub % 10, nb) < 0)
			return (-1);
	}
	else if (ft_printchar(nub + 48, nb) < 0)
		return (-1);
	return (0);
}
