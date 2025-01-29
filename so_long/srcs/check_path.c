/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:46:24 by afontan           #+#    #+#             */
/*   Updated: 2025/01/29 11:15:39 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_collectible_c(t_start *start)
{
	int	i;
	int	j;

	i = 0;
	start->index_c = 0;
	while (i < start->h_map)
	{
		j = 0;
		while (j < start->l_map)
		{
			if (start->map[i][j] == 'C')
				start->index_c ++;
			j++;
		}
		i++;
	}
}

void	pos_player(t_start *start, t_point **pt)
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
				(*pt)->x = j;
				(*pt)->y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	reset_visited(t_start *start, int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < start->h_map)
	{
		j = 0;
		while (j < start->l_map)
			visited[i][j++] = 0;
		i++;
	}
}

void	free_visited(t_start *start, int **visited)
{
	int	i;

	i = 0;
	while (i < start->h_map)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	check_connectivity(t_start *start)
{
	t_point	*pt;
	int		**visited;
	int		i;

	i = 0;
	start->check_e = 0;
	pt = (t_point *)malloc(sizeof(t_point));
	if (!pt)
		return (0);
	visited = malloc(start->h_map * sizeof(int *));
	if (!visited)
		return (0);
	while (i < start->h_map)
		visited[i++] = malloc(start->l_map * sizeof(int));
	reset_visited(start, visited);
	if (!final_check(start, pt, visited))
		return (0);
	return (1);
}
