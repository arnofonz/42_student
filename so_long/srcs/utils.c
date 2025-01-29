/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:15:27 by afontan           #+#    #+#             */
/*   Updated: 2025/01/29 09:06:39 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_on_mlx(t_start *start, void *img, int x, int y)
{
	mlx_put_image_to_window(start->mlx, start->win, img,
		x * start->width, y * start->height);
}

void	draw_map_suite(t_start *start, int x, int y)
{
	while (start->map[y] != NULL)
	{
		x = 0;
		while (start->map[y][x] != '\0')
		{
			if (start->map[y][x] == '1')
				put_on_mlx(start, start->wall, x, y);
			else if (start->map[y][x] == '0')
				put_on_mlx(start, start->found, x, y);
			else if (start->map[y][x] == 'C')
				put_on_mlx(start, start->ball, x, y);
			else if (start->map[y][x] == 'E')
			{
				if (start->collectible != 0)
					put_on_mlx(start, start->cage, x, y);
				else
					put_on_mlx(start, start->cage_v, x, y);
			}
			else if (start->map[y][x] == 'P')
				put_on_mlx(start, start->player, x, y);
			x++;
		}
		y++;
	}
}

void	draw_map(t_start *start)
{
	check_collectible(start);
	draw_map_suite(start, 0, 0);
	if (!start->win)
	{
		free_all(start);
		mlx_destroy_display(start->mlx);
		free(start->mlx);
		free(start);
		exit(1);
	}
}

int	is_valid_c(t_start *start, int x, int y)
{
	if (x < 0 || x > start->l_map)
		return (0);
	if (y < 0 || y > start->h_map)
		return (0);
	if (start->map[y][x] == '1' || start->map[y][x] == 'E')
		return (0);
	return (1);
}

int	is_valid_e(t_start *start, int x, int y)
{
	if (x < 0 || x > start->l_map)
		return (0);
	if (y < 0 || y > start->h_map)
		return (0);
	if (start->map[y][x] == '1')
		return (0);
	return (1);
}
