/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:02:47 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/16 10:10:55 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/so_long.h"

static int	lst_ligne(t_list **list, int fd)
{
	t_list	*new_node;
	char	*ligne;

	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
		{
			free(ligne);
			break ;
		}
		new_node = ft_lstnew(ligne);
		if (!new_node)
		{
			free(ligne);
			return (-1);
		}
		ft_lstadd_back(list, new_node);
	}
	return (0);
}

static char	*ft_strdup_no_nl(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	if (src[ft_strlen(src) - 1] == '\n')
		src[ft_strlen(src) - 1] = 0;
	dup = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	**create_map_array(t_list *list)
{
	char	**map_array;
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(list);
	map_array = malloc(sizeof(char *) * len + 1);
	if (!map_array)
		return (NULL);
	while (list)
	{
		map_array[i] = ft_strdup_no_nl(list->content);
		list = list->next;
		i++;
	}
	map_array[i] = ft_calloc(1, 1);
	return (map_array);
}

char	**parsing(int fd)
{
	t_list	*list;
	char	**map_array;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list = NULL;
	if (lst_ligne(&list, fd) < 0)
	{
		ft_lstclear(&list, free);
		return (NULL);
	}
	map_array = create_map_array(list);
	ft_lstclear(&list, free);
	return (map_array);
}
