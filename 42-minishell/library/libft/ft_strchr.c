/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tdechand <tdechand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2022/10/31 13:35:46 by Tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp_s;

	i = 0;
	tmp_s = (char *)s;
	while (tmp_s[i])
	{
		if (tmp_s[i] == (char)c)
			return (&tmp_s[i]);
		i++;
	}
	if (tmp_s[i] == (char)c)
		return (&tmp_s[i]);
	else
		return (NULL);
}
