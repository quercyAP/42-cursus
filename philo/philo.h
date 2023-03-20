/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:55:59 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/17 20:53:38 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philosopher	t_philosopher;

typedef struct s_simulation_params
{
	int					num_philosophers;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		start_time;
	int					num_eat;
	pthread_mutex_t		*print_lock;
	int					simulation_stopped;
	pthread_mutex_t		*stop_lock;
	int					philosopher_died;
	t_philosopher		*philosophers;
}						t_simulation_params;

typedef struct s_philosopher
{
	int					id;
	t_simulation_params	*params;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	int					is_alive;
	struct timeval		last_meal;
}						t_philosopher;

// Initialisation des philosophes et des mutex pour les fourchettes.
void					initialize_philosophers(t_philosopher *philosophers,
							pthread_mutex_t *forks,
							t_simulation_params *params);

// Fonction de simulation pour un philosophe
// (doit être exécutée dans un thread).
void					*philosopher_simulation(void *arg);
void					eat(t_philosopher *philosopher);
void					sleep_and_think(t_philosopher *philosopher);
void					*supervisor_thread(void *arg);

// Vérification si un philosophe est en vie.
int						is_philosopher_alive(t_philosopher *philosopher);

// Affichage des logs.
void					print_log(t_philosopher *philosopher,
							const char *status);

int						ft_atoi(const char *str);
unsigned long			get_current_time_ms(unsigned long start_time);
void					wait_with_id(int id);

#endif // PHILO_H
