/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:09:06 by afontan           #+#    #+#             */
/*   Updated: 2025/01/09 15:27:19 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_min(t_stack **stack_a)
{
	t_stack	*check;
	int		min_value;
	int		position;
	int		min_pos;

	check = *stack_a;
	min_value = check ->value;
	min_pos = 0;
	position = 0;
	while (check != NULL)
	{
		if (check ->value < min_value)
		{
			min_value = check ->value;
			min_pos = position;
		}
		check = check->next;
		position++;
	}
	return (min_pos);
}

int	check_min(t_stack **stack, int index)
{
	t_stack	*check;

	check = *stack;
	while (check != NULL)
	{
		if (index > check->index)
			return (0);
		check = check->next;
	}
	return (1);
}

int	check_max(t_stack **stack, int index)
{
	t_stack	*check;

	check = *stack;
	while (check != NULL)
	{
		if (index < check->index)
			return (0);
		check = check->next;
	}
	return (1);
}

int	check_pos(t_stack **stack, int to_find)
{
	int		count;
	t_stack	*curent;

	curent = *stack;
	count = 0;
	while (curent != NULL)
	{
		if (curent->index == to_find)
			return (count);
		count++;
		curent = curent->next;
	}
	return (0);
}
