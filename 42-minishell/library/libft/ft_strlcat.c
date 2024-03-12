/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tdechand <tdechand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2022/10/31 13:35:46 by Tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

static size_t	len(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	if (!dst && dstsize == 0)
		return (len(src));
	src_len = len(src);
	dst_len = len(dst);
	if (dstsize <= 0)
		return (src_len);
	i = 0;
	while (((dst_len + i) < (dstsize - 1)) && src[i] != '\0')
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
	{
		dst[i + dst_len] = '\0';
		return (src_len + dst_len);
	}
}
