/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:14:18 by afontan           #+#    #+#             */
/*   Updated: 2025/01/28 09:57:07 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	moove_up(t_start *start, t_point *pos, int type)
{
	char	tmp;

	if (type == 1)
	{
		tmp = start->map[pos->y][pos->x];
		start->map[pos->y][pos->x] = start->map[pos->y - 1][pos->x];
		start->map[pos->y - 1][pos->x] = tmp;
	}
	else if (type == 2)
	{
		tmp = start->map[pos->y][pos->x];
		start->map[pos->y][pos->x] = '0';
		start->map[pos->y - 1][pos->x] = tmp;
	}
}

void	moove_down(t_start *start, t_point *pos, int type)
{
	char	tmp;

	if (type == 1)
	{
		tmp = start->map[pos->y][pos->x];
		start->map[pos->y][pos->x] = start->map[pos->y + 1][pos->x];
		start->map[pos->y + 1][pos->x] = tmp;
	}
	else if (type == 2)
	{
		tmp = start->map[pos->y][pos->x];
		start->map[pos->y][pos->x] = '0';
		start->map[pos->y + 1][pos->x] = tmp;
	}
}

void	moove_left(t_start *start, t_point *pos, int type)
{
	char	tmp;

	if (type == 1)
	{
		tmp = start->map[pos->y][pos->x];
		start->map[pos->y][pos->x] = start->map[pos->y][pos->x - 1];
		start->map[pos->y][pos->x - 1] = tmp;
	}
	else if (type == 2)
	{
		tmp = start->map[pos->y][pos->x];
		start->map[pos->y][pos->x] = '0';
		start->map[pos->y][pos->x - 1] = tmp;
	}
}

void	moove_right(t_start *start, t_point *pos, int type)
{
	char	tmp;

	if (type == 1)
	{
		tmp = start->map[pos->y][pos->x];
		start->map[pos->y][pos->x] = start->map[pos->y][pos->x + 1];
		start->map[pos->y][pos->x + 1] = tmp;
	}
	else if (type == 2)
	{
		tmp = start->map[pos->y][pos->x];
		start->map[pos->y][pos->x] = '0';
		start->map[pos->y][pos->x + 1] = tmp;
	}
}

void	do_moves(t_start *start, t_point *pos, int dir)
{
	int	tmp;

	tmp = is_valid_move(start, pos->new_x, pos->new_y);
	if (is_valid_move(start, pos->new_x, pos->new_y))
	{
		if (dir == UP)
			moove_up(start, pos, tmp);
		else if (dir == DOWN)
			moove_down(start, pos, tmp);
		else if (dir == LEFT)
			moove_left(start, pos, tmp);
		else if (dir == RIGHT)
			moove_right(start, pos, tmp);
		start->moves++;
		ft_printf("Moves N. : %d\n", start->moves);
	}
}
