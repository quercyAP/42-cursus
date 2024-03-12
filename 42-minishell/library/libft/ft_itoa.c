/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tdechand <tdechand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2022/10/31 13:35:46 by Tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void	memcount(unsigned int nb, int *count)
{
	if (nb >= 10)
	{
		memcount(nb / 10, count);
		memcount(nb % 10, count);
	}
	else
		(*count)++;
}

static unsigned int	absoluter(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

static void	recursive_budy(char *ret, int *i, unsigned int nb)
{
	if (nb >= 10)
	{
		recursive_budy(ret, i, nb / 10);
		recursive_budy(ret, i, nb % 10);
	}
	else
	{
		ret[*i] = nb + 48;
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*ret;
	int				i;
	int				count;

	i = 0;
	count = 0;
	nb = absoluter(n);
	memcount(nb, &count);
	if (n < 0)
	{
		ret = ft_calloc((count + 2), sizeof(char));
		if (!ret)
			return (NULL);
		ret[0] = '-';
		i++;
	}
	else
		ret = ft_calloc((count + 1), sizeof(char));
	if (!ret)
		return (NULL);
	recursive_budy(ret, &i, nb);
	return (ret);
}
