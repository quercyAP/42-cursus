/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:10:24 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/13 17:30:22 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * sign);
}

void	print_message(t_philosopher *philo, char *message)
{
	struct timeval	curr_time;
	int				elapsed_time;

	gettimeofday(&curr_time, NULL);
	elapsed_time = (curr_time.tv_sec - philo->start_time.tv_sec) * 1000
		+ (curr_time.tv_usec - philo->start_time.tv_usec) / 1000;
	pthread_mutex_lock(&philo->print);
	printf("%d %d %s\n", elapsed_time, philo->id, message);
	pthread_mutex_unlock(&philo->print);
}

void	eat(t_philosopher *philo)
{
	printf("left fork = %i\n", philo->left_fork);
	pthread_mutex_lock(&philo->forks[philo->left_fork]);
	print_message(philo, "has taken a fork");
	printf("right fork = %i\n", philo->right_fork);
	pthread_mutex_lock(&philo->forks[philo->right_fork]);
	print_message(philo, "has taken a fork");
	gettimeofday(&philo->last_meal_time, NULL);
	print_message(philo, "is eating");
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->forks[philo->right_fork]);
}

void	die(t_philosopher *philo)
{
	print_message(philo, "died");
}

void	*philosopher_thread(void *arg)
{
	t_philosopher	*philo;
	struct timeval	curr_time;
	unsigned int	elapsed_time;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 && philo->count > 1)
		usleep(philo->time_to_die / philo->count);
	while (1)
	{
		eat(philo);
		gettimeofday(&curr_time, NULL);
		elapsed_time = (curr_time.tv_sec - philo->last_meal_time.tv_sec)
			* 1000 + (curr_time.tv_usec - philo->last_meal_time.tv_usec) / 1000;
		if (elapsed_time >= philo->time_to_die)
		{
			die(philo);
			return (NULL);
		}
		print_message(philo, "is sleeping");
		usleep(philo->time_to_sleep * 1000);
		print_message(philo, "is thinking");
		if (philo->num_meals != -1 && philo->num_meals-- == 0)
			return (NULL);
	}
	return (NULL);
}
