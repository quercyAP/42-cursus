/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:55:48 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/23 15:37:12 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_params(t_simulation_params *params, int argc, char **argv)
{
	params->start_time = get_current_time_ms(0);
	params->num_philosophers = atoi(argv[1]);
	params->time_to_die = atoi(argv[2]);
	params->time_to_eat = atoi(argv[3]);
	params->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		params->num_eat = atoi(argv[5]);
	else
		params->num_eat = -1;
	params->philosopher_died = 0;
	params->simulation_stopped = 0;
	params->print_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	params->stop_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(params->stop_lock, NULL);
	pthread_mutex_init(params->print_lock, NULL);
	params->philosophers = NULL;
}

void	join_threads(pthread_t *threads, t_simulation_params *params)
{
	int	i;

	i = 0;
	while (i < params->num_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

static void	start_threads(pthread_t *threads, t_philosopher *philosophers,
		t_simulation_params *params)
{
	int	i;

	i = 0;
	while (i < params->num_philosophers)
	{
		if (params->num_philosophers > 0)
			wait_with_id(philosophers->id);
		pthread_create(&threads[i], NULL, philosopher_simulation,
			&philosophers[i]);
		i++;
	}
}

static void	ft_free(t_simulation_params *params)
{
	pthread_mutex_destroy(params->print_lock);
	pthread_mutex_destroy(params->stop_lock);
	free(params->print_lock);
	free(params->stop_lock);
}

int	main(int argc, char **argv)
{
	t_simulation_params	params;
	t_philosopher		*philosophers;
	pthread_mutex_t		*forks;
	pthread_t			*threads;
	pthread_t			supervisor;

	if (check_args(argc, argv))
		return (ft_perror("ERROR: Bad argument"));
	init_params(&params, argc, argv);
	philosophers = (t_philosopher *)malloc(params.num_philosophers
			* sizeof(t_philosopher));
	params.philosophers = philosophers;
	forks = (pthread_mutex_t *)malloc(params.num_philosophers
			* sizeof(pthread_mutex_t));
	threads = (pthread_t *)malloc(params.num_philosophers * sizeof(pthread_t));
	initialize_philosophers(philosophers, forks, &params);
	pthread_create(&supervisor, NULL, supervisor_thread, (void *)&params);
	start_threads(threads, philosophers, &params);
	pthread_join(supervisor, NULL);
	join_threads(threads, &params);
	free(philosophers);
	free(forks);
	free(threads);
	ft_free(&params);
	return (0);
}
