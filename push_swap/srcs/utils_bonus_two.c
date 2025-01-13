/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:23:08 by afontan           #+#    #+#             */
/*   Updated: 2025/01/13 12:24:20 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pu_bonus(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || stack_b == NULL)
		return ;
	my_push_front(stack_a, stack_b);
}

void	rro_bonus(t_stack **stack)
{
	r_rotate (stack);
}

void	rrr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
}
