/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putullnbrb_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2022/12/05 07:00:09 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_putullnbrb_pf(unsigned long long n, int *count)
{
	if (n >= 16)
	{
		ft_putullnbrb_pf(n / 16, count);
		ft_putullnbrb_pf(n % 16, count);
	}
	else
		if (ft_putchar_pf("0123456789abcdef"[n], count) == -1)
			return (-1);
	return (0);
}
