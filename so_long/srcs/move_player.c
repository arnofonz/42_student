/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:30:57 by afontan           #+#    #+#             */
/*   Updated: 2025/01/28 09:57:47 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	is_end(t_start *start, t_point *pos, int x, int y)
{
	if ((start->map[y][x] == 'E' && start->collectible == 0))
	{
		free_all(start);
		if (start->mlx)
			mlx_destroy_display(start->mlx);
		free(start->mlx);
		free (pos);
		free(start);
		exit(0);
	}
}

int	is_valid_move(t_start *start, int x, int y)
{
	if (x < 0 || x > start->l_map)
		return (0);
	if (y < 0 || y > start->h_map)
		return (0);
	if (start->map[y][x] == '1' || start->map[y][x] == 'E')
		return (0);
	if (start->map[y][x] == 'C')
		return (2);
	return (1);
}

void	player_pos(t_start *start, t_point **pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < start->h_map)
	{
		j = 0;
		while (j < start->l_map)
		{
			if (start->map[i][j] == 'P')
			{
				(*pos)->x = j;
				(*pos)->y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	move_player(t_start *start, int direction)
{
	t_point	*pos;

	pos = (t_point *)malloc(sizeof(t_point));
	player_pos(start, &pos);
	pos->new_x = pos->x;
	pos->new_y = pos->y;
	if (direction == UP)
		pos->new_y--;
	else if (direction == DOWN)
		pos->new_y++;
	else if (direction == LEFT)
		pos->new_x--;
	else if (direction == RIGHT)
		pos->new_x++;
	is_end(start, pos, pos->new_x, pos->new_y);
	do_moves(start, pos, direction);
	mlx_clear_window(start->mlx, start->win);
	draw_map(start);
	free(pos);
}

int	key_hook(int keycode, t_start *start)
{
	if (keycode == 119)
		move_player(start, UP);
	if (keycode == 115)
		move_player(start, DOWN);
	if (keycode == 97)
		move_player(start, LEFT);
	if (keycode == 100)
		move_player(start, RIGHT);
	return (0);
}
