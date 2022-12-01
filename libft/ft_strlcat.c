/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marinv@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:56:49 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/06 16:19:23 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (size > 0)
	{
		while (dest[i] && i < size)
			i++;
		i2 = i;
		while (src[i - i2] && i < size -1)
		{
			dest[i] = src[i - i2];
			i++;
		}
		if (i2 < size)
			dest[i] = '\0';
	}
	return (i2 + ft_strlen(src));
}
