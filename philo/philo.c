/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:55:48 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/13 16:29:00 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(int argc, char **argv, pthread_mutex_t *forks, int nb)
{
	t_philosopher	*philo;
	pthread_t		*threads;
	pthread_mutex_t	print;
	int				i;

	philo = (t_philosopher *)malloc(nb * sizeof(t_philosopher));
	threads = (pthread_t *)malloc(nb * sizeof(pthread_t));
	i = -1;
	while (++i < nb)
		pthread_mutex_init(&forks[i], NULL);
	pthread_mutex_init(&print, NULL);
	i = -1;
	while (++i < nb)
	{
		philo[i].print = print;
		philo[i].forks = forks;
		philo[i].count = nb;
		philo[i].id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % nb;
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].time_to_eat = ft_atoi(argv[3]);
		philo[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo[i].num_meals = ft_atoi(argv[5]);
		else
			philo[i].num_meals = -1;
		gettimeofday(&philo[i].start_time, NULL);
		gettimeofday(&philo[i].last_meal_time, NULL);
		pthread_create(&threads[i], NULL, philosopher_thread, &philo[i]);
	}
	i = -1;
	while (++i < nb)
		pthread_join(threads[i], NULL);
	i = -1;
	while (++i < nb)
		pthread_mutex_destroy(&forks[i]);
	free(forks);
	free(philo);
	free(threads);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t		*forks;
	int					nb_philo;

	if (argc < 5 || argc > 6)
	{
		printf("error\n");
		return (1);
	}
	nb_philo = ft_atoi(argv[1]);
	forks = malloc(nb_philo * sizeof(pthread_mutex_t));
	start_simulation(argc, argv, forks, nb_philo);

	return (0);
}
