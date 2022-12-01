/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:34:37 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/17 12:52:46 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_base(unsigned long int nbr, char *base, int *nb)
{
	unsigned int			blen;

	blen = ft_strlen(base);
	if (nbr >= blen)
	{
		if (ft_printnbr_base(nbr / blen, base, nb) < 0)
			return (-1);
		if (ft_printnbr_base(nbr % blen, base, nb) < 0)
			return (-1);
	}
	else if (ft_printchar(base[nbr], nb) < 0)
		return (-1);
	return (0);
}
