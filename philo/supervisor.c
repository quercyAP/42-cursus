/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:27:58 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/03 11:08:43 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	are_done(t_philosopher *philo, t_simulation_params *params)
{
	int	i;
	int	done;
	int	meals_count;

	if (params->num_eat == -1)
		return (0);
	i = -1;
	done = -1;
	while (++i < params->num_philosophers)
	{
		pthread_mutex_lock(&philo->params->mutex[MEALS]);
		meals_count = philo[i].eat_count;
		pthread_mutex_unlock(&philo->params->mutex[MEALS]);
		if (meals_count >= params->num_eat)
			if (++done == params->num_philosophers - 1)
				return (1);
	}
	return (0);
}

static void	routine(t_simulation_params *params, t_philosopher *philo, int i)
{
	pthread_mutex_lock(philo[i].sleep);
	set_died(params);
	print_log(&philo[i], "died");
	pthread_mutex_unlock(philo[i].sleep);
}

int	supervisor(t_simulation_params *params, t_philosopher *philo)
{
	int				i;
	unsigned long	last_meal;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&params->mutex[MEALS]);
		last_meal = philo[i].last_meal;
		pthread_mutex_unlock(&params->mutex[MEALS]);
		if (last_meal && are_done(philo, params))
		{
			set_stop(params);
			break ;
		}
		if (last_meal && get_current_time_ms()
			- last_meal > params->time_to_die)
		{
			routine(params, philo, i);
			break ;
		}
		i = (i + 1) % params->num_philosophers;
	}
	return (1);
}
