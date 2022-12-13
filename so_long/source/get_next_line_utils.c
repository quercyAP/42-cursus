/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:40 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/13 11:28:39 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"

void	*ft_clean(char **rest)
{
	free(*rest);
	*rest = NULL;
	return (NULL);
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
