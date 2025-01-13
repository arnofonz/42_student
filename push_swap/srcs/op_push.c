/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:35:24 by afontan           #+#    #+#             */
/*   Updated: 2025/01/13 10:11:54 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_push_front(t_stack **src, t_stack **dst)
{
	t_stack	*push_stack;

	push_stack = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->back = NULL;
	push_stack ->back = NULL;
	if (!*dst)
	{
		*dst = push_stack;
		push_stack->next = NULL;
	}
	else
	{
		push_stack->next = *dst;
		push_stack->next->back = push_stack;
		*dst = push_stack;
	}
	push_stack->back = NULL;
	*dst = push_stack;
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	if (*stack_b == NULL)
		return ;
	my_push_front(stack_a, stack_b);
	ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	my_push_front(stack_a, stack_b);
	ft_putstr("pb\n");
}
