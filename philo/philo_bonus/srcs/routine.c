/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:48:52 by afontan           #+#    #+#             */
/*   Updated: 2025/03/26 09:33:51 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	check_death(t_philo *philo)
{
	if (actual_time() - philo->last_meal
		> (unsigned long)philo->data->time_to_die)
	{
		philo->data->died = 1;
		sem_wait(philo->data->print_lock);
		printf("%lu %d %s\n", actual_time()
			- philo->data->start_time, philo->id, "died");
		philo->data->philo_stop = 1;
		return (1);
	}
	return (0);
}

static int	check_meal_limit(t_philo *philo)
{
	if (philo->data->nb_of_eat != -1 && philo->meals >= philo->data->nb_of_eat)
	{
		philo->data->philo_stop = 1;
		return (1);
	}
	return (0);
}

static void	*check_monitor(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!philo->data->philo_stop)
	{
		usleep(100);
		if (check_death(philo) || check_meal_limit(philo))
			break ;
	}
	if (philo->data->died == 1)
		exit(1);
	else
		exit(0);
}

void	routine(t_philo *philo)
{
	if (pthread_create(&philo->check_monitor, NULL, &check_monitor, philo))
		ft_error("Error creating thread");
	if (philo->id % 2 == 1)
		usleep(1000);
	while (1)
	{
		sem_wait(philo->data->forks);
		print_mess("has taken a fork", philo, philo->id);
		sem_wait(philo->data->forks);
		print_mess("has taken a fork", philo, philo->id);
		ft_usleep(philo->data->time_to_eat);
		sem_wait(philo->data->meal_lock);
		philo->last_meal = actual_time();
		sem_post(philo->data->meal_lock);
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		philo->meals++;
		print_mess("is sleeping", philo, philo->id);
		ft_usleep(philo->data->time_to_sleep);
		print_mess("is thinking", philo, philo->id);
	}
	if (pthread_join(philo->check_monitor, NULL))
		ft_error("Error : failed to join thread");
}
