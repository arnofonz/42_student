/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:25:18 by afontan           #+#    #+#             */
/*   Updated: 2025/01/07 10:03:51 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_to_5(t_stack **stack_a, t_stack **stack_b, int nb)
{
	if (nb == 2)
		sort_2(stack_a);
	if (nb == 3)
		sort_3(stack_a);
	if (nb == 4)
		sort_4(stack_a, stack_b);
	if (nb == 5)
		sort_5(stack_a, stack_b);
}

void	sort_2(t_stack **stack_a)
{
	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if ((*stack_a)->next != NULL
		&& (*stack_a)->value > (*stack_a)->next ->value)
		sa(stack_a);
}

void	sort_3(t_stack **stack_a)
{
	int	first;
	int	middle;
	int	last;

	first = (*stack_a)->value;
	middle = (*stack_a)->next->value;
	last = (*stack_a)->next->next->value;
	if (first > middle && middle < last && last > first)
		sa(stack_a);
	if (first > middle && middle > last && last < first)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > middle && middle < last && last < first)
		ra(stack_a);
	else if (first < middle && middle > last && last > first)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < middle && middle > last && last < first)
		rra(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*check_a;
	t_stack	*list;

	check_a = (*stack_a);
	while (check_a ->next -> next != NULL)
	{
		list = (*stack_a);
		if (is_min(stack_a) > 1)
		{
			if (is_min(stack_a) <= len_stack(list) / 2)
				ra(stack_a);
			else if (is_min(stack_a) > len_stack(list) / 2)
				rra(stack_a);
			list = (*stack_a);
			check_a = (*stack_a);
		}
		else
			pb(stack_a, stack_b);
		check_a = check_a -> next;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*check_a;
	t_stack	*list;

	check_a = (*stack_a);
	while (check_a->next->next != NULL)
	{
		list = (*stack_a);
		if (is_min(stack_a) + 1 > 1)
		{
			if (is_min(stack_a) + 1 <= len_stack(list) / 2)
				ra(stack_a);
			else if (is_min(stack_a) + 1 > len_stack(list) / 2)
				rra(stack_a);
			list = (*stack_a);
			check_a = (*stack_a);
		}
		else
			pb(stack_a, stack_b);
		check_a = check_a -> next;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
