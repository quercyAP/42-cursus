/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:10:06 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/16 15:05:13 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char	**test_map;
	int		fd;
	int		i;
	t_elem	*elem;

	fd = open(argv[1], O_RDONLY);
	test_map = parsing(fd);
	if (!is_rect(test_map))
	{
		ft_putstr_fd("Map Error\nthe map is not rectangular.\n", 1);
		return (0);
	}
	if (!is_close(test_map))
	{
		ft_putstr_fd("Map Error\nthe map is not close", 1);
		return (0);
	}
	i = 0;
	while (test_map[i][0])
	{
		printf("%s\n", test_map[i]);
		i++;
	}
	elem = malloc(sizeof(t_elem));
	elem_init(elem, test_map);
	printf("spawn est en x:%i y:%i", elem->p_exit->x, elem->p_exit->y);
	close(fd);
}
