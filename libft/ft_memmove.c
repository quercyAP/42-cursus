/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:38:53 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/04 16:29:30 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	size_t	j;

	j = 0;
	i = n;
	if (src == NULL && dest == NULL)
		return (dest);
	i--;
	if (dest > src)
	{
		while (i >= 0)
		{
			*((char *)(dest + i)) = *((char *)(src + i));
			i--;
		}
	}
	else
	{
		while (j < n)
		{
			*((char *)(dest + j)) = *((char *)(src + j));
			j++;
		}
	}
	return (dest);
}
