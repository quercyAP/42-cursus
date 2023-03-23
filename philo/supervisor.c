/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:27:58 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/23 15:36:14 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor_thread(void *arg)
{
	t_simulation_params	*params;
	int					i;

	i = 0;
	params = (t_simulation_params *)arg;
	while (params->philosopher_died == 0)
	{
		i = 0;
		pthread_mutex_lock(params->stop_lock);
		while (i < params->num_philosophers)
		{
			if (!is_philosopher_alive(&params->philosophers[i]))
			{
				params->philosopher_died = i + 1;
				params->die_time = get_current_time_ms(params->start_time);
				return (NULL);
			}
			i++;
		}
		pthread_mutex_unlock(params->stop_lock);
		usleep(1000);
	}
	return (NULL);
}
