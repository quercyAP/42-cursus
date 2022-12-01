/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marinv@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:29:40 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/12 18:28:40 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	foundcharset(const char *str, char c, int i)
{
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static	int	countstring(const char *str, char c)
{
	int	i;
	int	strcount;

	i = 0;
	strcount = 0;
	while (str[i])
	{
		if (i != foundcharset(str, c, i))
		{
			i = foundcharset(str, c, i) - 1;
			i++;
			strcount++;
		}
		else
			i++;
	}
	return (strcount);
}

static	void	*freeall(char **strs, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static	int	copy(const char *str, char c, char **strs)
{
	int	j;
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (k < countstring(str, c))
	{
		j = 0;
		if (i != foundcharset(str, c, i))
		{
			strs[k] = malloc(sizeof(char) * foundcharset(str, c, i) - i + 1);
			if (!strs[k])
			{
				freeall(strs, k);
				return (-1);
			}
			while (i < foundcharset(str, c, i) && str[i])
				strs[k][j++] = str[i++];
			strs[k++][j] = '\0';
		}
		i++ ;
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**strs;

	if (str == NULL)
		return (NULL);
	strs = ft_calloc(countstring(str, c) + 1, sizeof(char *));
	if (strs == 0)
		return (NULL);
	if (copy(str, c, strs) == -1)
		return (NULL);
	return (strs);
}
