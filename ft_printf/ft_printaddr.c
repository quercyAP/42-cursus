/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:53:02 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/17 11:19:02 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaddr(unsigned long int addr, int *nb)
{
	if (ft_printchar('0', nb) < 0 || ft_printchar('x', nb) < 0)
		return (-1);
	if (ft_printnbr_base(addr, "0123456789abcdef", nb) < 0)
		return (-1);
	return (0);
}
