/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:10:24 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/20 09:59:44 by glamazer         ###   ########.fr       */
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

void	wait_with_id(int id)
{
	int	wait_time;

	wait_time = id * 1000 - 50;
	if (wait_time > 0)
		usleep(wait_time);
}

unsigned long	get_current_time_ms(unsigned long start_time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
		- start_time);
}

void	print_log(t_philosopher *philosopher, const char *status)
{
	unsigned long	timestamp;

	pthread_mutex_lock(philosopher->params->print_lock);
	if (!philosopher->params->simulation_stopped)
	{
		timestamp = get_current_time_ms(philosopher->params->start_time);
		printf("%lu %d %s\n", timestamp, philosopher->id, status);
	}
	pthread_mutex_unlock(philosopher->params->print_lock);
}


void	initialize_philosophers(t_philosopher *philosophers,
								pthread_mutex_t *forks,
								t_simulation_params *params)
{
	int i;

	for (i = 0; i < params->num_philosophers; i++)
	{
		philosophers[i].id = i + 1;
		philosophers[i].params = params;
		philosophers[i].left_fork = &forks[i];
		philosophers[i].right_fork = &forks[(i + 1) % params->num_philosophers];
		philosophers[i].is_alive = 1;
		gettimeofday(&philosophers[i].last_meal, NULL);
	}
}