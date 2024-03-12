/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2022/12/09 15:11:33 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	is_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (is_in_set(set, s1[i]))
		{
			i++;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

static size_t	get_end(char const *s1, char const *set)
{
	int		i;
	size_t	count;

	i = ft_strlen(s1);
	count = 0;
	while (i >= 0)
	{
		if (is_in_set(set, s1[i - 1]))
		{
			i--;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == 0)
		return (ft_strdup(""));
	if (set[0] == 0)
		return (ft_strdup(s1));
	start = get_start(s1, set);
	end = get_end(s1, set);
	len = ft_strlen(s1) - start - end;
	return (ft_substr(s1, start, len));
}
