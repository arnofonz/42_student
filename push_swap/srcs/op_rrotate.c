/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:33:41 by afontan           #+#    #+#             */
/*   Updated: 2024/12/19 17:14:24 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = (*stack_a);
	while (last ->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	second_last->next = NULL;
	ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = (*stack_b);
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	second_last ->next = NULL;
	ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_a;
	t_stack	*second_last_a;
	t_stack	*last_b;
	t_stack	*second_last_b;

	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last_a = (*stack_a);
	while (last_a ->next)
	{
		second_last_a = last_a;
		last_a = last_a->next;
	}
	my_push_front(stack_a, last_a->value, last_a->index);
	second_last_a->next = NULL;
	last_b = (*stack_b);
	while (last_b ->next)
	{
		second_last_b = last_b;
		last_b = last_b ->next;
	}
	my_push_front(stack_b, last_b->value, last_b->index);
	second_last_b ->next = NULL;
	ft_putstr("rrr\n");
}
