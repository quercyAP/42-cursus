/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:10:06 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/20 12:25:31 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	return (0);
	char	**test_map;
	int		fd;
	int		i;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	test_map = parsing(fd);
	if (!check_error(test_map))
	{
		free_map(test_map);
		return (0);
	}
	i = 0;
	while (test_map[i][0])
	{
		printf("%s\n", test_map[i]);
		i++;
	}
	free_map(test_map);
	close(fd);
}
