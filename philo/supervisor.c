/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:27:58 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/24 17:41:24 by lamazerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	died(t_philosopher *philosopher)
{
	print_log(philosopher, "died");
}

void	*supervisor_thread(void *arg)
{
	t_simulation_params	*params;
	int					i;

	i = 0;
	params = (t_simulation_params *)arg;
	while (params->philosopher_died == 0)
	{
		i = 0;
		while (i < params->num_philosophers)
		{
			if (!is_philosopher_alive(&params->philosophers[i]))
			{
				pthread_mutex_lock(params->stop_lock);
				params->philosophers->is_alive = 0;
				params->philosopher_died = i + 1;
				params->die_time = get_current_time_ms(params->start_time);
				died(&params->philosophers[i]);
				pthread_mutex_unlock(params->stop_lock);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
