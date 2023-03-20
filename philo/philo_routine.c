/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:56:29 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/20 10:01:51 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor_thread(void *arg)
{
	t_simulation_params	*params;
	int					i;

	params = (t_simulation_params *)arg;
	while (1)
	{
		for (i = 0; i < params->num_philosophers; i++)
		{
			if (!is_philosopher_alive(&params->philosophers[i]))
			{
				params->philosopher_died = 1;
				return (NULL);
			}
		}
	}
}

int	is_philosopher_alive(t_philosopher *philosopher)
{
	unsigned long	current_time;
	unsigned long	time_since_last_meal;

	current_time = get_current_time_ms(philosopher->params->start_time);
	time_since_last_meal = current_time - (philosopher->last_meal.tv_sec * 1000
			+ philosopher->last_meal.tv_usec / 1000
			- philosopher->params->start_time);
	if (time_since_last_meal < philosopher->params->time_to_die)
		return (1);
	return (0);
}

void	eat(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	print_log(philosopher, "has taken a fork");
	pthread_mutex_lock(philosopher->right_fork);
	if (!philosopher->params->philosopher_died)
	{
		pthread_mutex_unlock(philosopher->right_fork);
		pthread_mutex_unlock(philosopher->left_fork);
	}
	print_log(philosopher, "has taken a fork");
	print_log(philosopher, "is eating");
	gettimeofday(&philosopher->last_meal, NULL);
	usleep(philosopher->params->time_to_eat * 1000);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

void	sleep_and_think(t_philosopher *philosopher)
{
	print_log(philosopher, "is sleeping");
	usleep(philosopher->params->time_to_sleep * 1000);
	print_log(philosopher, "is thinking");
}

void	*philosopher_simulation(void *arg)
{
	t_philosopher	*philosopher;
	int				eat_count;

	philosopher = (t_philosopher *)arg;
	eat_count = 0;
	wait_with_id(philosopher->id);
	while (philosopher->params->num_eat == -1
		|| eat_count < philosopher->params->num_eat)
	{
		eat(philosopher);
		eat_count++;
		sleep_and_think(philosopher);
		if (philosopher->params->philosopher_died)
		{
			pthread_mutex_lock(philosopher->params->stop_lock);
			if (philosopher->params->simulation_stopped == 0)
				print_log(philosopher, "died");
			philosopher->params->simulation_stopped = 1;
			pthread_mutex_unlock(philosopher->params->stop_lock);
			break ;
		}
	}
	return (NULL);
}
