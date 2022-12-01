/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:02:55 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/07 15:18:13 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		k;

	i = 0;
	if (n == 0)
		return (0);
	while (*((unsigned char *)(s1 + i)) == *((unsigned char *)(s2 + i))
			&& i < n -1)
		i++;
	k = *((unsigned char *)(s1 + i)) - *((unsigned char *)(s2 + i));
	return (k);
}
