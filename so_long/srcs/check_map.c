/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:02:10 by afontan           #+#    #+#             */
/*   Updated: 2025/01/28 10:32:10 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_side(t_start *start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < start->l_map)
	{
		if (start->map[0][i] != '1' || start->map[start->h_map - 1][i] != '1')
			return (0);
		i++;
	}
	while (j < start->h_map)
	{
		if (start->map[j][0] != '1' || start->map[j][start->l_map - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_size(t_start *start)
{
	int	i;
	int	size;

	size = ft_strlen(start->map[0]);
	i = 1;
	while (i < start->h_map - 1)
	{
		if (ft_strlen(start->map[i]) != size)
			return (0);
		i++;
	}
	if (ft_strlen(start->map[i++]) != size - 1)
		return (0);
	if (start->h_map <= 3 && start->l_map <= 3)
		return (2);
	return (1);
}

int	check_char(t_start *start)
{
	int	i;
	int	j;

	i = 0;
	while (i < start->h_map)
	{
		j = 0;
		while (j < start->l_map)
		{
			if (start->map[i][j] != '1'
				&& start->map[i][j] != '0'
				&& start->map[i][j] != 'P'
				&& start->map[i][j] != 'C'
				&& start->map[i][j] != 'E'
				&& start->map[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_pers_and_item(t_start *start, int countP, int countC, int countE)
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
				countP++;
			if (start->map[i][j] == 'C')
				countC++;
			if (start->map[i][j] == 'E')
				countE++;
			j++;
		}
		i++;
	}
	if (countE > 1 || countP > 1)
		return (0);
	if ((countP && countE && countC))
		return (1);
	return (0);
}

int	map_is_valid(t_start *start)
{
	if (check_side(start) == 0)
		return (is_error(11));
	if (check_size(start) == 2)
		return (is_error(12));
	if (check_size(start) == 0)
		return (is_error(13));
	if (check_char(start) == 0)
		return (is_error(14));
	if (check_pers_and_item(start, 0, 0, 0) == 0)
		return (is_error(15));
	if (check_connectivity(start) == 0)
		return (-1);
	return (1);
}
