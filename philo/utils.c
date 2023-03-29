/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:10:24 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/29 15:55:23 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * sign);
}

void	init_mutex(t_simulation_params *params)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = malloc(sizeof(pthread_mutex_t) * NB);
	i = 0;
	while (i < NB)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	params->mutex = mutex;
}

unsigned long	get_current_time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000
			+ current_time.tv_usec / 1000));
}

void	print_log(t_philosopher *philosopher, const char *status)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&philosopher->params->mutex[PRINT]);
	if ((!check_died(philosopher) && !check_stop(philosopher))
		|| *status == 'd')
	{
		timestamp = get_current_time_ms() - philosopher->params->start_time;
		printf("%lu %d %s\n", timestamp, philosopher->id, status);
	}
	pthread_mutex_unlock(&philosopher->params->mutex[PRINT]);
}

void	initialize_philosophers(t_philosopher *philosophers,
								pthread_mutex_t *forks,
								t_simulation_params *params)
{
	int	i;

	i = 0;
	while (i < params->num_philosophers)
		pthread_mutex_init(&forks[i++], NULL);
	i = 0;
	while (i < params->num_philosophers)
	{
		philosophers[i].sleep = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philosophers[i].sleep, NULL);
		philosophers[i].id = i + 1;
		philosophers[i].params = params;
		philosophers[i].eat_count = 0;
		philosophers[i].left_fork = &forks[i];
		philosophers[i].right_fork = &forks[(i + 1) % params->num_philosophers];
		philosophers[i].last_meal = params->start_time;
		i++;
	}
}
