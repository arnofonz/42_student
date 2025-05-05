/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:48:09 by afontan           #+#    #+#             */
/*   Updated: 2025/03/24 11:55:53 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	actual_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	destroy_all(char *str, t_table *table)
{
	int	i;

	i = 0;
	if (str)
		ft_error(str);
	pthread_mutex_destroy(&table ->print_lock);
	pthread_mutex_destroy(&table ->dead_lock);
	pthread_mutex_destroy(&table ->meal_lock);
	while (i < table->nb_of_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

int	ft_usleep(size_t millisecond)
{
	usleep(millisecond * 1000);
	return (0);
}

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (nb);
}
