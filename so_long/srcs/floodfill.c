/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:02:21 by afontan           #+#    #+#             */
/*   Updated: 2025/01/29 10:25:19 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill_c(t_start *start, int x, int y, int **visited)
{
	if (!is_valid_c(start, x, y) || visited[y][x])
		return ;
	visited[y][x] = 1;
	if (start->map[y][x] == 'C')
	{
		start->index_c--;
		if (start->index_c == 0)
			start->check_c = 1;
	}
	flood_fill_c(start, x - 1, y, visited);
	flood_fill_c(start, x + 1, y, visited);
	flood_fill_c(start, x, y - 1, visited);
	flood_fill_c(start, x, y + 1, visited);
	return ;
}

void	flood_fill_e(t_start *start, int x, int y, int **visited)
{
	if (!is_valid_e(start, x, y) || visited[y][x])
		return ;
	visited[y][x] = 1;
	if (start->map[y][x] == 'E')
		start->check_e = 1;
	flood_fill_e(start, x - 1, y, visited);
	flood_fill_e(start, x + 1, y, visited);
	flood_fill_e(start, x, y - 1, visited);
	flood_fill_e(start, x, y + 1, visited);
	return ;
}

int	final_check(t_start *start, t_point *pt, int **visited)
{
	pos_player(start, &pt);
	check_collectible_c(start);
	flood_fill_c(start, pt->x, pt->y, visited);
	reset_visited(start, visited);
	pos_player(start, &pt);
	flood_fill_e(start, pt->x, pt->y, visited);
	if (start->check_e == 0 || start->check_c == 0)
	{
		ft_putstr_fd("ERROR : invalid path\n", 2);
		free_visited(start, visited);
		free(pt);
		return (0);
	}
	free_visited(start, visited);
	free(pt);
	return (1);
}
