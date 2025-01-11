/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:52:20 by afontan           #+#    #+#             */
/*   Updated: 2025/01/09 14:05:42 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*head;

	head = *stack_a;
	my_push_back(stack_a, head -> value, head->index);
	*stack_a = (*stack_a)->next;
	free(head);
	ft_putstr("ra\n");
}

void	rb(t_stack **stack_b)
{
	t_stack	*head;

	head = *stack_b;
	my_push_back(stack_b, head -> value, head->index);
	*stack_b = (*stack_b)->next;
	free(head);
	ft_putstr("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head1;
	t_stack	*head2;

	head1 = *stack_a;
	my_push_back(stack_a, head1 -> value, head1->index);
	*stack_a = (*stack_a)->next;
	head2 = *stack_b;
	my_push_back(stack_b, head2 -> value, head2->index);
	*stack_b = (*stack_b)->next;
	ft_putstr("rr\n");
}
