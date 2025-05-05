/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:31:36 by afontan           #+#    #+#             */
/*   Updated: 2025/03/26 09:34:09 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	init_sem(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/meal_lock");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->nb_of_philo);
	data->print_lock = sem_open("/print_lock", O_CREAT, 0644, 1);
	data->meal_lock = sem_open("/meal_lock", O_CREAT, 0644, 1);
	if (data->forks == SEM_FAILED || data->print_lock == SEM_FAILED)
	{
		ft_error("Error initializing semaphores");
		exit(1);
	}
}

void	init_data(t_data *data, int ac, char **av)
{
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_of_eat = ft_atoi(av[5]);
	else
		data->nb_of_eat = -1;
	data->start_time = actual_time();
	data->philo_stop = 0;
	data->died = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_of_philo);
	if (!data->philos)
	{
		printf("Erreur: Allocation de data->philos a échoué\n");
		return ;
	}
}
