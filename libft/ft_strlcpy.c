/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marinv@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:27:16 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/12 18:29:01 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	srclen;
	unsigned int	dstlen;

	i = 0;
	srclen = 0;
	dstlen = dstsize;
	while (src[srclen] != '\0')
	{
		srclen++;
	}
	if (dstlen > 0)
	{
		while (src[i] && i < dstlen - 1)
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (srclen);
}
