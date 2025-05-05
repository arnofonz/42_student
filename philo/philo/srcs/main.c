/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:27:09 by afontan           #+#    #+#             */
/*   Updated: 2025/03/24 11:53:57 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_valid_entries(int ac, char **av)
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

int	main(int ac, char **av)
{
	t_table		table;
	t_philos	philos[MAX_PHILO];

	if (is_valid_entries(ac, av))
		return (1);
	init_table(&table, philos);
	init_forks(&table, ft_atoi(av[1]));
	init_philos(&table, av);
	create_thread(&table);
	destroy_all(NULL, &table);
}
