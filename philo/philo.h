/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:55:59 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/28 15:29:31 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_philosopher	t_philosopher;

typedef enum e_mutexes
{
	PRINT,
	MEALS,
	STOP,
	DIED,
	NB
}	t_mutexes;

typedef struct s_simulation_params
{
	int					num_philosophers;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		start_time;
	int					num_eat;
	pthread_mutex_t		*mutex;
	int					sim_stopped;
	int					philo_died;
	t_philosopher		*philosophers;
}						t_simulation_params;

typedef struct s_philosopher
{
	int					id;
	t_simulation_params	*params;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	int					eat_count;
	unsigned long		last_meal;
}						t_philosopher;

void					initialize_philosophers(t_philosopher *philosophers,
							pthread_mutex_t *forks,
							t_simulation_params *params);
void					*philosopher_simulation(void *arg);
int						eat(t_philosopher *philosopher);
void					sleep_and_think(t_philosopher *philosopher);
int						supervisor(t_simulation_params *params,
							t_philosopher *philo);
int						is_philosopher_alive(t_philosopher *philosopher);
void					print_log(t_philosopher *philosopher,
							const char *status);
int						ft_atoi(const char *str);
unsigned long			get_current_time_ms(void);
int						wait_with_id(int id);
int						check_args(int argc, char **argv);
int						ft_perror(char *msg);
void					set_stop(t_simulation_params *params);
void					set_died(t_simulation_params *params);
int						check_stop(t_philosopher *philo);
int						check_died(t_philosopher *philo);
void					ft_sleep(unsigned long millisec);
void					init_mutex(t_simulation_params *params);

#endif
