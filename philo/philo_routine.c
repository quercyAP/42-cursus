/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:56:29 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/24 16:41:41 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philosopher_alive(t_philosopher *philosopher)
{
	unsigned long	current_time;
	unsigned long	time_since_last_meal;

	current_time = get_current_time_ms(0);
	time_since_last_meal = current_time - ((philosopher->last_meal.tv_sec * 1000
				+ philosopher->last_meal.tv_usec / 1000));
	if (time_since_last_meal <= philosopher->params->time_to_die)
		return (1);
	return (0);
}

void	eat(t_philosopher *philosopher, int *eat_count)
{
	pthread_mutex_lock(philosopher->left_fork);
	pthread_mutex_lock(philosopher->params->stop_lock);
	if (philosopher->params->philosopher_died)
	{
		pthread_mutex_unlock(philosopher->params->stop_lock);
		pthread_mutex_unlock(philosopher->left_fork);
		return ;
	}
	print_log(philosopher, "has taken a fork");
	pthread_mutex_unlock(philosopher->params->stop_lock);
	pthread_mutex_lock(philosopher->right_fork);
	print_log(philosopher, "has taken a fork");
	(*eat_count)++;
	print_log(philosopher, "is eating");
	gettimeofday(&philosopher->last_meal, NULL);
	usleep(philosopher->params->time_to_eat * 1000);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

void	sleep_and_think(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->params->stop_lock);
	if (!philosopher->params->philosopher_died)
	{
		pthread_mutex_unlock(philosopher->params->stop_lock);
		print_log(philosopher, "is sleeping");
	}
	pthread_mutex_unlock(philosopher->params->stop_lock);
	usleep(philosopher->params->time_to_sleep * 1000);
	pthread_mutex_lock(philosopher->params->stop_lock);
	if (!philosopher->params->philosopher_died)
	{
		pthread_mutex_unlock(philosopher->params->stop_lock);
		print_log(philosopher, "is thinking");
	}
	pthread_mutex_unlock(philosopher->params->stop_lock);
}

void	*philosopher_simulation(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	while ((philosopher->params->num_eat == -1
			|| philosopher->eat_count < philosopher->params->num_eat))
	{
		pthread_mutex_lock(philosopher->params->stop_lock);
		if (philosopher->params->philosopher_died)
		{
			pthread_mutex_unlock(philosopher->params->stop_lock);
			break ;
		}
		pthread_mutex_unlock(philosopher->params->stop_lock);
		eat(philosopher, &philosopher->eat_count);
		pthread_mutex_lock(philosopher->params->stop_lock);
		if (philosopher->eat_count == philosopher->params->num_eat
			|| !philosopher->is_alive)
		{
			pthread_mutex_unlock(philosopher->params->stop_lock);
			break ;
		}
		pthread_mutex_unlock(philosopher->params->stop_lock);
		sleep_and_think(philosopher);
	}
	return (NULL);
}
