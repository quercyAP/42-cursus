/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:56:29 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/29 15:55:48 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_eating(t_philosopher *philosopher)
{
	print_log(philosopher, "is sleeping");
	if (philosopher->id % 2 == 0)
	{
		pthread_mutex_unlock(philosopher->right_fork);
		pthread_mutex_unlock(philosopher->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philosopher->left_fork);
		pthread_mutex_unlock(philosopher->right_fork);
	}
	ft_sleep(philosopher->params->time_to_sleep);
	return (1);
}

int	eat(t_philosopher *philosopher)
{
	if (philosopher->id % 2 == 0)
		pthread_mutex_lock(philosopher->left_fork);
	else
		pthread_mutex_lock(philosopher->right_fork);
	print_log(philosopher, "has taken a fork");
	if (philosopher->id % 2 == 0)
		pthread_mutex_lock(philosopher->right_fork);
	else
		pthread_mutex_lock(philosopher->left_fork);
	print_log(philosopher, "has taken a fork");
	print_log(philosopher, "is eating");
	pthread_mutex_lock(&philosopher->params->mutex[MEALS]);
	philosopher->last_meal = get_current_time_ms();
	philosopher->eat_count++;
	pthread_mutex_unlock(&philosopher->params->mutex[MEALS]);
	if (check_stop(philosopher))
	{
		end_eating(philosopher);
		return (0);
	}
	pthread_mutex_lock(philosopher->sleep);
	ft_sleep(philosopher->params->time_to_eat);
	pthread_mutex_unlock(philosopher->sleep);
	end_eating(philosopher);
	return (1);
}

void	*philosopher_simulation(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	if (philosopher->id % 2 == 0)
		ft_sleep(philosopher->params->time_to_eat);
	while (1)
	{
		if (check_died(philosopher))
			break ;
		if (!eat(philosopher))
			break ;
		print_log(philosopher, "is thinking");
	}
	return (NULL);
}
