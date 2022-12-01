/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:37:59 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/27 12:09:45 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!stash || !clean_node)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = ft_calloc(sizeof(char),
			((ft_strlen(last->content) - i)) + 1);
	if (!clean_node)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	free_stash(*stash);
	*stash = clean_node;
}

static void	extract_line(t_list *stash, char **ligne)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	generate_line(ligne, stash);
	if (!*ligne)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*ligne)[j++] = stash->content[i];
				break ;
			}
			(*ligne)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
}

static void	add_to_stash(t_list **stash, char *buff, int readed)
{
	int		i;
	t_list	*new_node;
	t_list	*last;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = ft_calloc(sizeof(char), (readed + 1));
	if (!new_node->content)
		return ;
	i = 0;
	while (buff[i] && i < readed)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	if (!*stash)
	{
		*stash = new_node;
		return ;
	}
	last = ft_lstlast(*stash);
	last->next = new_node;
}

static int	read_and_stash(t_list **stash, int fd)
{
	char	*buff;
	int		readed;

	readed = 1;
	while (!found_newline(*stash) && readed != 0)
	{	
		buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!buff)
			return (0);
		readed = read(fd, buff, BUFFER_SIZE);
		if ((!*stash && !readed) || readed == -1)
		{
			if (readed == -1)
			{
				free(buff);
				return (-1);
			}
			free(buff);
			return (0);
		}	
		add_to_stash(stash, buff, readed);
		free(buff);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*ligne;
	int				read_error;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ligne = NULL;
	read_error = read_and_stash(&stash, fd);
	if (!stash || read_error == -1)
	{
		free_stash(stash);
		stash = NULL;
		free(ligne);
		return (NULL);
	}
	extract_line(stash, &ligne);
	clean_stash(&stash);
	if (ligne[0] == 0)
	{
		free_stash(stash);
		stash = NULL;
		free(ligne);
		return (NULL);
	}
	return (ligne);
}
