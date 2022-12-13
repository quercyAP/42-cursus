/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:10:06 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/13 16:22:40 by glamazer         ###   ########.fr       */
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

	fd = open(argv[1], O_RDONLY);
	test_map = parsing(fd);
	if (!test_map)
	i = 0;
	while (test_map[i][0])
	{
		printf("%s", test_map[i]);
		i++;
	}
	close(fd);
}