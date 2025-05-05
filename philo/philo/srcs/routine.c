/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:37:20 by afontan           #+#    #+#             */
/*   Updated: 2025/03/24 11:53:07 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_mess(char *str, t_philos *philo, int philo_num)
{
	size_t	time;

	pthread_mutex_lock(philo->print_lock);
	time = actual_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, philo_num, str);
	pthread_mutex_unlock(philo->print_lock);
}

void	thinking(t_philos *philo)
{
	print_mess("is thinking 🧠", philo, philo->id);
}

void	sleeping(t_philos *philo)
{
	print_mess("is sleeping 🛏️", philo, philo->id);
	ft_usleep(philo->table->time_to_sleep);
}

void	eat(t_philos *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_mess("has taken a fork 🍴", philo, philo->id);
	if (philo->table->nb_of_philo == 1)
	{
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_mess("has taken a fork 🍴", philo, philo->id);
	philo->eating = 1;
	print_mess("is eating 🥪", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = actual_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
