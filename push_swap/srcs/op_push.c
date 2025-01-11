/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:35:24 by afontan           #+#    #+#             */
/*   Updated: 2025/01/09 16:27:48 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_push_front(t_stack **stack, int new_value, int new_index)
{
	t_stack	*new_node;

	new_node = my_lstnew(new_value, new_index);
	if (!new_node)
		return ;
	if (*stack != NULL)
		(*stack)->back = new_node;
	new_node ->next = *stack;
	*stack = new_node;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	my_push_front(stack_a, (*stack_b)->value, (*stack_b)->index);
	*stack_b = (*stack_b)->next;
	ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	my_push_front(stack_b, (*stack_a)->value, (*stack_a)->index);
	*stack_a = (*stack_a)->next;
	ft_putstr("pb\n");
}
