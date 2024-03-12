/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2022/12/05 06:59:18 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_putnbr_pf(int n, int *count)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * -1;
		if (ft_putchar_pf('-', count) == -1)
			return (-1);
	}
	else
		nb = n;
	if (nb >= 10)
	{
		if (ft_putnbr_pf(nb / 10, count) == -1)
			return (-1);
		if (ft_putnbr_pf(nb % 10, count) == -1)
			return (-1);
	}
	else
		if (ft_putchar_pf((nb + 48), count) == -1)
			return (-1);
	return (0);
}
