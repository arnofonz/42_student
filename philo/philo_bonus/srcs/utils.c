/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:44:58 by afontan           #+#    #+#             */
/*   Updated: 2025/03/26 09:34:30 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

size_t	actual_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_usleep(size_t millisecond)
{
	usleep(millisecond * 1000);
	return (0);
}

void	print_mess(char *str, t_philo *philo, int philo_num)
{
	size_t	time;

	sem_wait(philo->data->print_lock);
	if (!philo->data->philo_stop)
	{
		time = actual_time() - philo->data->start_time;
		printf("%zu %d %s\n", time, philo_num, str);
	}
	sem_post(philo->data->print_lock);
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

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
}
