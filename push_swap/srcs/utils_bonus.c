/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:49:15 by afontan           #+#    #+#             */
/*   Updated: 2025/01/21 10:18:33 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sw_bonus(t_stack **stack)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	swap_arg(*stack);
}

void	ss_bonus(t_stack **stack_a, t_stack **stack_b)
{
	if (((*stack_a) == NULL || (*stack_a)->next == NULL)
		&& ((*stack_b) == NULL || (*stack_b)->next == NULL))
		return ;
	else if ((*stack_a) == NULL || (*stack_a)->next == NULL)
	{
		swap_arg(*stack_b);
		return ;
	}
	else if ((*stack_b) == NULL || (*stack_b)->next == NULL)
	{
		swap_arg(*stack_a);
		return ;
	}
	swap_arg(*stack_a);
	swap_arg(*stack_b);
}

void	ro_bonus(t_stack **stack)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	rotate(stack);
}

void	rr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a) == NULL || (*stack_a)->next == NULL
		|| (*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	rotate(stack_a);
	rotate(stack_b);
}
