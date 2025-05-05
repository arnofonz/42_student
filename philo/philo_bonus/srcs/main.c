/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:05:36 by afontan           #+#    #+#             */
/*   Updated: 2025/03/26 09:39:38 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	is_valid_entries(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		ft_error("Error : bad nb of argumets\n");
		return (1);
	}
	if (ft_atoi(av[1]) > 200)
	{
		ft_error("Error : too much philo\n");
		return (1);
	}
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
		{
			ft_error("Error : bad type of arguments\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static void	end_philo(t_data *data)
{
	t_data	*tmp;
	int		i;
	int		status;

	tmp = data;
	i = 0;
	while (i < data->nb_of_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < tmp->nb_of_philo)
			{
				kill(tmp->philos[i].pid, SIGKILL);
				i++;
			}
			break ;
		}
		i++;
	}
}

static void	end_sem(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	sem_close(tmp->meal_lock);
	sem_close(tmp->print_lock);
	sem_close(tmp->forks);
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/death_lock");
	free(tmp->philos);
	free(tmp);
}

static void	start_simu(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philo)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid == -1)
			ft_error("fork error");
		if (data->philos[i].pid == 0)
		{
			data->philos[i].id = i + 1;
			data->philos[i].meals = 0;
			data->philos[i].last_meal = actual_time();
			data->philos[i].data = data;
			routine(&data->philos[i]);
		}
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (is_valid_entries(ac, av))
		return (1);
	init_data(data, ac, av);
	init_sem(data);
	start_simu(data);
	end_philo(data);
	end_sem(data);
}
