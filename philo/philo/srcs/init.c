/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:14:56 by afontan           #+#    #+#             */
/*   Updated: 2025/03/24 11:56:33 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned long long	time_diff(struct timeval end, struct timeval start)
{
	return (end.tv_sec - start.tv_sec * 1000000 + end.tv_usec - start.tv_usec);
}

static void	init_param(t_table *table, char **av)
{
	table->nb_of_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->nb_of_eat = ft_atoi(av[5]);
	else
		table->nb_of_eat = -1;
}

void	init_philos(t_table *table, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		table->philos[i].id = i + 1;
		table->philos[i].eating = 0;
		table->philos[i].meals_eaten = 0;
		init_param(table, av);
		table->philos[i].start_time = actual_time();
		table->philos[i].last_meal = actual_time();
		table->philos[i].dead = &table->dead_flag;
		table->philos[i].left_fork = &table->forks[i];
		if (i == 0)
			table->philos[i].right_fork = &table->forks[table->nb_of_philo - 1];
		else
			table->philos[i].right_fork = &table->forks[i - 1];
		table->philos[i].table = table;
		table->philos[i].print_lock = &table->philos->table->print_lock;
		table->philos[i].dead_lock = &table->philos->table->dead_lock;
		table->philos[i].meal_lock = &table->philos->table ->meal_lock;
		i++;
	}
}

void	init_forks(t_table *table, int nb_of_philo)
{
	int	i;

	i = 0;
	while (i < nb_of_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	init_table(t_table *table, t_philos *philos)
{
	table->dead_flag = 0;
	table->philos = philos;
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
	pthread_mutex_init(&table->print_lock, NULL);
}
