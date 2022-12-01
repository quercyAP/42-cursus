/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marinv@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:36:19 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/14 12:08:59 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	findstartindex(const char *s1, const char *set)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (set[j] != s1[i] && set[j])
			j++;
		if (j == ft_strlen(set))
			break ;
		else
			j = 0;
		i++;
	}
	return (i);
}

static	int	findendindex(const char *s1, const char *set)
{
	int		i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i >= 0)
	{
		while (set[j] != s1[i] && set[j])
			j++;
		if (j == ft_strlen(set))
			break ;
		else
			j = 0;
		i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = findstartindex(s1, set);
	end = findendindex(s1, set);
	if (end < start)
		return (ft_strdup(""));
	str = ft_substr(s1, start, end - start + 1);
	if (!str)
		return (NULL);
	return (str);
}
