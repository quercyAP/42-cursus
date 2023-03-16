/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:55:59 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/13 16:16:29 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int				id;
	int				left_fork;
	int				right_fork;
	unsigned int	time_to_die;
	int				time_to_eat;
	int				count;
	int				time_to_sleep;
	int				num_meals;
	struct timeval	start_time;
	pthread_mutex_t	*forks;
	struct timeval	last_meal_time;
	pthread_mutex_t	print;
}					t_philosopher;


void	start_simulation(int argc, char **argv, pthread_mutex_t *forks, int nb);
void	print_message(t_philosopher *philo, char *message);
void	eat(t_philosopher *philo);
void	*philosopher_thread(void *arg);
int		ft_atoi(const char *str);

#endif
