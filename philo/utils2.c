/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:07:49 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/28 15:17:54 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(unsigned long millisec)
{
	int	i;

	i = 0;
	while (++i < 20)
		usleep(millisec * 50);
}

int	check_died(t_philosopher *philo)
{
	pthread_mutex_lock (&philo->params->mutex[DIED]);
	if (philo->params->philo_died)
	{
		pthread_mutex_unlock (&philo->params->mutex[DIED]);
		return (1);
	}
	pthread_mutex_unlock (&philo->params->mutex[DIED]);
	return (0);
}

int	check_stop(t_philosopher *philo)
{
	pthread_mutex_lock (&philo->params->mutex[STOP]);
	if (philo->params->sim_stopped)
	{
		pthread_mutex_unlock (&philo->params->mutex[STOP]);
		return (1);
	}
	pthread_mutex_unlock (&philo->params->mutex[STOP]);
	return (0);
}

void	set_died(t_simulation_params *params)
{
	pthread_mutex_lock (&params->mutex[DIED]);
	params->philo_died = 1;
	pthread_mutex_unlock (&params->mutex[DIED]);
}

void	set_stop(t_simulation_params *params)
{
	pthread_mutex_lock (&params->mutex[STOP]);
	params->sim_stopped = 1;
	pthread_mutex_unlock (&params->mutex[STOP]);
}
