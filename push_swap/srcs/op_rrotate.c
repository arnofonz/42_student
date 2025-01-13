/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:33:41 by afontan           #+#    #+#             */
/*   Updated: 2025/01/13 11:32:19 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = go_end(*stack);
	last->back->next = NULL;
	last->next = *stack;
	last->back = NULL;
	*stack = last;
	last->next->back = last;
}

void	rra(t_stack **stack_a)
{
	r_rotate(stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b)
{
	r_rotate (stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_putstr("rrr\n");
}
