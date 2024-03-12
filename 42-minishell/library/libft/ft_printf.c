/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2022/12/05 06:58:57 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>
#include "libft.h"

static int	ft_format(const char *str, va_list args, int *count, int *i)
{
	(*i) += 1;
	if (str[1] == 'c' )
		return (ft_putchar_pf((char)va_arg(args, int), count));
	else if (str[1] == 's')
		return (ft_putstr_pf((char *)va_arg(args, char *), count));
	else if (str[1] == 'p')
	{
		if (ft_putstr_pf("0x", count) == -1)
			return (-1);
		return (ft_putullnbrb_pf((unsigned long long)va_arg(args,
					unsigned long long), count));
	}
	else if (str[1] == 'd' || str[1] == 'i')
		return (ft_putnbr_pf((int)va_arg(args, int), count));
	else if (str[1] == 'u')
		return (ft_putunbr_pf((unsigned int)va_arg(args, unsigned int), count));
	else if (str[1] == 'x')
		return (ft_putnbrb_pf((int)va_arg(args, int), count));
	else if (str[1] == 'X')
		return (ft_putnbrbcap_pf((int)va_arg(args, int), count));
	else if (str[1] == '%')
		return (ft_putchar_pf('%', count));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			if (ft_putchar_pf(str[i], &count) == -1)
				return (-1);
		}
		else
		{
			if (ft_format(str + i, args, &count, &i) == -1)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// int main()
// {
// 	printf("real-%-3d\n", 10);
// 	ft_printf("fake-%-3d\n", 10);
// }