/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:27:58 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/20 15:37:52 by glamazer         ###   ########.fr       */
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
		while (i < params->num_philosophers)
		{
			if (!is_philosopher_alive(&params->philosophers[i]))
			{
				params->philosopher_died = 1;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
