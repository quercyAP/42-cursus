/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:55:21 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/16 14:31:38 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/so_long.h"

int	is_rect(char **map_array)
{
	int	i;
	int	len;

	i = 1;
	if (map_len(map_array) < 3 || ft_strlen(map_array[0]) < 3)
		return (0);
	while (map_array[i][0])
	{
		if (ft_strlen(map_array[i]) != ft_strlen(map_array[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	is_close(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[0][i])
	{
		if (map_array[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map_array[map_len(map_array) - 1][i])
	{
		if (map_array[map_len(map_array) - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map_array[i][0])
	{
		if (map_array[i][0] != '1'
			|| map_array[i][ft_strlen(map_array[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}