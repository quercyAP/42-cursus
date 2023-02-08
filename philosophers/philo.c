/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:55:48 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/08 15:02:43 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



static void	init_room(char **argv, int argc, t_philo *philo)
{
	philo->nb_philo = 
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (argc > 4 && argc < 7)
	{
		if (!check_arg(argv, argc))
		{
			free(philo);
			return (printf("Error\nBad argument\n"));
		}
		init_room(argv, argc, philo);
	}
}