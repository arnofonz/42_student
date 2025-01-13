/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:49:15 by afontan           #+#    #+#             */
/*   Updated: 2025/01/13 12:23:43 by afontan          ###   ########.fr       */
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
	swap_arg(*stack_a);
	swap_arg(*stack_b);
}

void	ro_bonus(t_stack **stack)
{
	rotate(stack);
}

void	rr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
