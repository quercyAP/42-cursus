/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:55:59 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/08 13:44:12 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_pihlo
{
	pthread_t		*philo;
	pthread_mutex_t	fork;
	int				nb_philo;
	int				i_philo;
	int				t_die;
	int				t_eat;
	int				t_meat;
	int				t_sleep;
	enum			e_state{think, fork, eat, sleep, died};
}					t_philo;

#endif