/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:21:25 by afontan           #+#    #+#             */
/*   Updated: 2025/01/17 10:33:15 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(t_stack *node)
{
	if (node)
		free(node);
}

t_stack	*go_end(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*my_lstnew(int new_value, int new_index)
{
	t_stack	*new_ct;

	new_ct = ft_calloc(1, sizeof(t_stack));
	if (!new_ct)
		return (NULL);
	new_ct ->value = new_value;
	new_ct ->index = new_index;
	new_ct ->next = NULL;
	new_ct ->back = NULL;
	return (new_ct);
}

void	my_push_back(t_stack **stack_a, int new_value, int new_index)
{
	t_stack	*last_node;
	t_stack	*new_node;

	new_node = my_lstnew(new_value, new_index);
	if (new_node == NULL)
		return ;
	if (*stack_a == NULL)
	{
		*stack_a = new_node;
		return ;
	}
	last_node = *stack_a;
	while (last_node -> next)
		last_node = last_node ->next;
	last_node ->next = new_node;
	new_node ->back = last_node;
}

void	ft_stack_clear(t_stack **lst, void (*del)(t_stack *))
{
	t_stack	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp);
	}
	*lst = NULL;
}
