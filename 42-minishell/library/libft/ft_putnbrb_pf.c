/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrb_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2022/12/05 06:59:25 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_putnbrb_pf(unsigned int n, int *count)
{
	if (n >= 16)
	{
		if (ft_putnbrb_pf(n / 16, count) == -1)
			return (-1);
		if (ft_putnbrb_pf(n % 16, count) == -1)
			return (-1);
	}
	else
		if (ft_putchar_pf("0123456789abcdef"[n], count) == -1)
			return (-1);
	return (0);
}
