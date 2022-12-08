/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:15:19 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/08 09:40:42 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*save_rest(int *ptr, char *rest)
{
	int		i;
	int		start;
	char	*tmp;

	i = 0;
	start = *ptr;
	tmp = NULL;
	if (ft_strchr(rest, '\n'))
	{
		tmp = ft_calloc(sizeof(char), (ft_strlen(rest) - start) + 1);
		if (!tmp)
			return (ft_clean(&rest));
		while (rest[start])
			tmp[i++] = rest[start++];
	}
	free(rest);
	rest = NULL;
	return (tmp);
}

static char	*extract_line(char *read_str, int *ptr)
{
	int		i;
	int		j;
	char	*ligne;

	j = 0;
	i = 0;
	if (!read_str)
		return (ft_clean(&read_str));
	while (read_str[i] && read_str[i] != '\n')
		i++;
	if (read_str[i] == '\n')
		i++;
	*ptr += i;
	ligne = ft_calloc(sizeof(char), i + 1);
	if (!ligne)
		return (NULL);
	while (j < i)
	{
		ligne[j] = read_str[j];
		j++;
	}
	return (ligne);
}

static char	*buffer_read(int fd, char *rest)
{
	int		charcount;
	char	*buffer;

	charcount = 1;
	if (!rest)
		rest = ft_calloc(1, 1);
	if (!rest)
		return (ft_clean(&rest));
	while (!ft_strchr(rest, '\n') && charcount > 0)
	{
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buffer)
		{
			free(buffer);
			ft_clean(&rest);
			return (NULL);
		}
		charcount = read(fd, buffer, BUFFER_SIZE);
		rest = ft_strcat(rest, buffer);
		if (!rest)
			return (ft_clean(&buffer));
		ft_clean(&buffer);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*ligne;
	static char	*rest;
	int			i;
	int			*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_clean(&rest));
	i = 0;
	ptr = &i;
	rest = buffer_read(fd, rest);
	if (!rest)
		return (ft_clean(&rest));
	ligne = extract_line(rest, ptr);
	if (!ligne)
		return (ft_clean(&rest));
	rest = save_rest(ptr, rest);
	if (!ligne[0])
	{
		ft_clean(&ligne);
		return (NULL);
	}
	return (ligne);
}
