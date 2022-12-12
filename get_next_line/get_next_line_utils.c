/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:40 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/08 09:53:59 by glamazer         ###   ########.fr       */
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
	free(*rest);
	*rest = NULL;
	return (NULL);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	while (i < size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

char	*ft_strcat(char *str, char *src)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	if (!src[0])
		return (str);
	temp = malloc(sizeof(char) * ft_strlen(str) + ft_strlen(src) + 1);
	if (!temp)
		return (ft_clean(&str));
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
	return (temp);
}
