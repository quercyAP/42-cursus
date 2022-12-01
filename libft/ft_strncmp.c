/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:28:09 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/07 14:38:58 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		k;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n -1 && s1[i] && s2[i])
		i++;
	k = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (k);
}
