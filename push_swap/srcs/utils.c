/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:59:35 by afontan           #+#    #+#             */
/*   Updated: 2025/01/10 18:00:06 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_ps(const char *str)
{
	long	x;
	int		i;
	int		sign;

	i = 0;
	x = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10;
		x = x + str[i] - 48;
		i++;
	}
	return (x * sign);
}

int	is_tried(t_stack *stack)
{
	t_stack	*check;
	t_stack	*tmp;

	check = stack;
	while (check != NULL)
	{
		tmp = check;
		while (tmp != NULL)
		{
			if (tmp ->value < check ->value)
				return (0);
			tmp = tmp ->next;
		}
		check = check ->next;
	}
	return (1);
}

void	copy_nbr(t_stack **stack_a, int *tab, int max)
{
	int		i;
	t_stack	*curent;

	i = 0;
	curent = *stack_a;
	while (curent != NULL)
	{
		i = 0;
		while (i < max)
		{
			if (tab[i] == curent ->value)
				curent->index = i;
			i++;
		}
		curent = curent ->next;
	}
}
