/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:36:20 by afontan           #+#    #+#             */
/*   Updated: 2025/01/10 17:50:38 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_arg(t_stack *stack)
{
	int	tmp;
	int	tmp_index;

	tmp = stack ->value;
	stack ->value = stack ->next ->value;
	stack ->next -> value = tmp;
	tmp_index = stack ->index;
	stack ->index = stack ->next ->index;
	stack ->next -> index = tmp_index;
}

void	sa(t_stack **stack_a)
{
	swap_arg(*stack_a);
	ft_putstr("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap_arg(*stack_b);
	ft_putstr("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_arg(*stack_a);
	swap_arg(*stack_b);
	ft_putstr("ss\n");
}
