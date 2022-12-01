/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:27:21 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/08 13:37:28 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char *)s1);
	while (i < n && s1[i])
	{
		while (s1[i] == s2[j] && s2[j] && i < n)
		{
			i++;
			j++;
		}
		if (j < ft_strlen(s2))
		{
			i -= j;
			i++;
			j = 0;
		}
		else
			return ((char *)s1 + i - ft_strlen(s2));
	}
	return (NULL);
}
