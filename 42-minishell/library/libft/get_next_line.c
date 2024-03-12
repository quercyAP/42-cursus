/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:58:35 by tdechand          #+#    #+#             */
/*   Updated: 2022/12/05 06:57:55 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*freeme(char **tofree)
{
	free(*tofree);
	*tofree = NULL;
	return (NULL);
}

char	*make_line(char **save)
{
	int		i;
	char	*ret_line;
	char	*temp;

	i = 0;
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	ret_line = ft_substr(*save, 0, i + 1);
	if (!ret_line)
		return (freeme(save));
	if ((*save) && (*save)[i + 1] == 0)
		freeme(save);
	else
	{
		temp = ft_substr(*save, (i + 1), ft_strlen(*save));
		if (!temp)
		{
			free(ret_line);
			return (freeme(save));
		}
		free(*save);
		*save = temp;
	}
	return (ret_line);
}

char	*ret_line(char **save, int b_count)
{
	char	*ret_line;

	if (!(*save) && b_count <= 0)
		return (NULL);
	if (ft_strchr(*save, '\n'))
	{
		ret_line = make_line(save);
		if (!ret_line)
			return (NULL);
	}
	else
	{
		ret_line = ft_strdup(*save);
		free(*save);
		*save = NULL;
	}
	return (ret_line);
}

static int	fline_or_join(char **save, char *buffer)
{
	char		*temp;

	if (!(*save))
	{
		(*save) = ft_strdup(buffer);
		if (!(*save))
		{
			free(buffer);
			return (0);
		}
	}
	else
	{
		temp = ft_strjoin((*save), buffer);
		free((*save));
		(*save) = temp;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	int			b_count;
	char		*buffer;
	static char	*save[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (freeme(&save[fd]));
	b_count = (int)read(fd, buffer, BUFFER_SIZE);
	if (b_count == -1)
		freeme(&save[fd]);
	while (b_count > 0)
	{
		buffer[b_count] = '\0';
		if (fline_or_join(&save[fd], buffer) == 0)
			return (NULL);
		if (save[fd] && ft_strchr(save[fd], '\n'))
			break ;
		b_count = (int)read(fd, buffer, BUFFER_SIZE);
		if (b_count == -1)
			freeme(&save[fd]);
	}
	free(buffer);
	return (ret_line(&save[fd], b_count));
}
