/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:11:59 by afontan           #+#    #+#             */
/*   Updated: 2025/01/13 11:27:26 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(t_stack *stack)
{
	int		i;
	t_stack	*curent;

	curent = stack;
	i = 0;
	while (curent != NULL)
	{
		curent = curent ->next;
		i++;
	}
	return (i);
}

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	find_min(t_stack **stack)
{
	int		min;
	t_stack	*check;

	check = *stack;
	min = check->index;
	while (check != NULL)
	{
		if (check ->index < min)
			min = check->index;
		check = check->next;
	}
	return (min);
}

int	find_max(t_stack **stack)
{
	int		max;
	t_stack	*check;

	max = 0;
	check = *stack;
	while (check != NULL)
	{
		if (check ->index > max)
			max = check->index;
		check = check->next;
	}
	return (max);
}

int	ft_lstcmp(t_stack **stack_a)
{
	t_stack	*curent;
	t_stack	*cmp;

	curent = (*stack_a);
	while (curent != NULL)
	{
		cmp = curent ->next;
		while (cmp != NULL)
		{
			if (cmp ->value == curent ->value)
				return (0);
			cmp = cmp ->next;
		}
		curent = curent->next;
	}
	return (1);
}
