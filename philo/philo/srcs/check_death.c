/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:03:01 by afontan           #+#    #+#             */
/*   Updated: 2025/03/24 11:57:43 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_dead(t_philos *philos, size_t time_to_die)
{
	pthread_mutex_lock(philos->meal_lock);
	if (actual_time() - philos->last_meal >= time_to_die && philos->eating == 0)
		return (pthread_mutex_unlock(philos->meal_lock), 1);
	pthread_mutex_unlock(philos->meal_lock);
	return (0);
}

int	check_if_dead(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->table->nb_of_philo)
	{
		if (philo_dead(&philos[i], philos[i].table->time_to_die))
		{
			print_mess("died", &philos[i], philos->id);
			pthread_mutex_lock(&philos[0].table->dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(&philos[0].table->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_philos *philo)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	if (philo[0].table->nb_of_eat == -1)
		return (0);
	while (i < philo->table->nb_of_philo)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].table->nb_of_eat)
			finished++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (finished == philo[0].table->nb_of_philo)
	{
		pthread_mutex_lock(&philo->table->dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(&philo->table->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *ptr)
{
	t_philos	*philos;

	philos = (t_philos *)ptr;
	while (1)
	{
		if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	}
	return (ptr);
}
