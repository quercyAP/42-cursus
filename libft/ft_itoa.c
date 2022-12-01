/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:19:56 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/12 18:20:18 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	revswap(char *str, int len, int neg)
{
	int		i;
	char	tmp;

	i = -1;
	if (neg == 1)
	{
		str[len] = '-';
		len++;
	}
	while (++i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
	str[len] = '\0';
}

static	int	len_alloc(long int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static	char	*copy(long int nb, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (nb < 0)
	{
		nb *= -1;
		j = 1;
	}
	while (nb > 0)
	{
		str[i++] = "0123456789"[nb % 10];
		nb = nb / 10;
	}
	revswap(str, i, j);
	return (str);
}

char	*ft_itoa(int n)
{
	char		*res;
	long int	nb;

	nb = n;
	res = ft_calloc(len_alloc(nb) + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (nb == 0)
	{
		res[0] = 48;
		return (res);
	}
	copy(nb, res);
	return (res);
}
