/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:25:03 by afontan           #+#    #+#             */
/*   Updated: 2025/01/29 11:18:51 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_start	*start;

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long <map_file>\n");
		return (EXIT_FAILURE);
	}
	start = (t_start *)malloc(sizeof(t_start));
	ft_bzero(start, sizeof(t_start));
	if (!start)
		return (EXIT_FAILURE);
	if (initialize_win_and_mlx(av, start) == -1)
	{
		free_map(start);
		mlx_destroy_display(start->mlx);
		free(start->mlx);
		free(start);
		return (0);
	}
	mlx_hook(start->win, 2, 1L << 0, key_hook, start);
	mlx_key_hook(start->win, &close_window, start);
	mlx_hook(start->win, 17, 0, &close_cross, start);
	mlx_loop(start->mlx);
	return (EXIT_SUCCESS);
}
