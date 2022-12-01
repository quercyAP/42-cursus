/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:29:43 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/17 12:54:56 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_format(const char *str, int i, va_list args, int *nb)
{
	int		n;

	n = 0;
	if (str[i] == 'c')
		n = ft_printchar(va_arg(args, int), nb);
	else if (str[i] == 's')
		n = ft_printstr(va_arg(args, char *), nb);
	else if (str[i] == 'p')
		n = ft_printaddr(va_arg(args, unsigned long), nb);
	else if (str[i] == 'd' || str[i] == 'i')
		n = ft_printnbr(va_arg(args, int), nb);
	else if (str[i] == 'u')
		n = ft_printunbr(va_arg(args, unsigned int), nb);
	else if (str[i] == 'x')
		n = ft_printnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", nb);
	else if (str[i] == 'X')
		n = ft_printnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", nb);
	else if (str[i] == '%')
		n = ft_printchar('%', nb);
	if (n < 0)
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		nb;
	va_list	args;
	int		*ptr;

	i = -1;
	nb = 0;
	ptr = &nb;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (ft_format(str, i + 1, args, ptr) < 0)
				return (-1);
			i++;
		}
		else if (ft_printchar(str[i], ptr) < 0)
			return (-1);
	}
	va_end(args);
	return (*ptr);
}
