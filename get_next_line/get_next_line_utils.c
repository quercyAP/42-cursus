/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:40 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/01 16:20:19 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	*ft_clean(char **rest)
{
	if (*rest)
		free(*rest);
	*rest = NULL;
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	i = 0;
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	while (i < size)
	{
		*((char *)(array + i)) = 0;
		i++;
	}
	return (array);
}

char	*ft_strcat(char *str, char *src)
{
	int		i;
	int		j;
	char	*temp;
	int		len;

	i = 0;
	len = ft_strlen(str) + ft_strlen(src) + 2;
	temp = malloc(sizeof(char) * len);
	if (!temp)
		return (ft_clean(&src));
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	ft_clean(&str);
	j = 0;
	while (src[j])
		temp[i++] = src[j++];
	temp[i] = 0;
	ft_clean(&src);
	return (temp);
}
