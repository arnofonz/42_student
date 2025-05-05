/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:46 by afontan           #+#    #+#             */
/*   Updated: 2025/03/25 11:18:22 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	dead_loop(t_philos *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*routine(void *ptr)
{
	t_philos	*philo;

	philo = (t_philos *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (ptr);
}

int	create_thread(t_table *table)
{
	pthread_t	checker;
	int			i;

	if (pthread_create(&checker, NULL, &monitor, table->philos) != 0)
		destroy_all("Thread error creation", table);
	i = 0;
	while (i < table->nb_of_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine,
				&table->philos[i]) != 0)
			destroy_all("Thread error creation", table);
		i++;
	}
	i = 0;
	if (pthread_join(checker, NULL) != 0)
		destroy_all("Thread join error", table);
	while (i < table->nb_of_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			destroy_all("Thread join error", table);
		i++;
	}
	return (0);
}
