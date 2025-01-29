/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:51:10 by afontan           #+#    #+#             */
/*   Updated: 2025/01/28 10:22:49 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_all(t_start *start)
{
	if (start->wall)
		mlx_destroy_image(start->mlx, start->wall);
	if (start->found)
		mlx_destroy_image(start->mlx, start->found);
	if (start->ball)
		mlx_destroy_image(start->mlx, start->ball);
	if (start->cage)
		mlx_destroy_image(start->mlx, start->cage);
	if (start->cage)
		mlx_destroy_image(start->mlx, start->cage_v);
	if (start->player)
		mlx_destroy_image(start->mlx, start->player);
	if (start->win)
		mlx_destroy_window(start->mlx, start->win);
	if (start->map)
		free_map(start);
}

void	free_map(t_start *start)
{
	int	i;

	i = 0;
	while (start->map[i] != NULL)
	{
		free(start->map[i]);
		start->map[i] = NULL;
		i++;
	}
	free(start->map);
	start->map = NULL;
	close (start->fd);
}

int	close_window(int keycode, t_start *start)
{
	if (keycode == 65307)
	{
		free_all(start);
		if (start->mlx)
			mlx_destroy_display(start->mlx);
		free(start->mlx);
		free(start);
		exit(0);
	}
	return (0);
}

int	close_cross(t_start *start)
{
	free_all(start);
	mlx_destroy_display(start->mlx);
	free(start->mlx);
	free(start);
	exit(0);
}
