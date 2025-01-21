/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:20:24 by afontan           #+#    #+#             */
/*   Updated: 2025/01/15 10:22:31 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**========================================================================
 *                      Verif le noeud cible de A vers B
 *========================================================================**/

int	verif_targ(int index_a, t_stack **stack_b)
{
	int		to_find;
	t_stack	*check_b;

	if (check_max (stack_b, index_a) == 1
		|| check_min (stack_b, index_a) == 1)
		return (find_max(stack_b));
	check_b = *stack_b;
	to_find = find_min(stack_b);
	while (check_b != NULL)
	{
		if (index_a > check_b->index && check_b->index > to_find)
			to_find = check_b ->index;
		check_b = check_b->next;
	}
	return (to_find);
}

/**========================================================================
 *                      Verif le noeud cible de B vers A
 *========================================================================**/

int	targ_ret(int index_b, t_stack **stack_a)
{
	int		to_find;
	t_stack	*check_b;

	if (check_max (stack_a, index_b) == 1)
		return (find_min(stack_a));
	check_b = *stack_a;
	to_find = find_max(stack_a);
	while (check_b != NULL)
	{
		if (index_b < check_b->index && check_b->index < to_find)
			to_find = check_b ->index;
		check_b = check_b->next;
	}
	return (to_find);
}

/**========================================================================
 *         Check la position du nb en fonction du milieu de la stack
 *========================================================================**/

int	ver_pos(t_stack **stack, int to_find)
{
	int		count;
	t_stack	*curent;

	curent = *stack;
	count = 0;
	while (curent != NULL)
	{
		if (curent->index == to_find)
			break ;
		count++;
		curent = curent->next;
	}
	if (count <= len_stack(*stack) / 2)
		return (count);
	else
		return (len_stack(*stack) - count);
	return (0);
}

/**========================================================================
 *                           Rotation finale stack A
 *========================================================================**/

void	final_rotate(t_stack **stack_a)
{
	int	rotate;

	rotate = check_pos(stack_a, 0);
	if (rotate < len_stack(*stack_a) / 2)
	{
		while (rotate)
		{
			ra(stack_a);
			rotate--;
		}
	}
	if (rotate >= len_stack(*stack_a) / 2)
	{
		rotate = len_stack(*stack_a) - rotate;
		while (rotate)
		{
			rra(stack_a);
			rotate--;
		}
	}
}

/**========================================================================
 *                           Algo de tri
 *========================================================================**/

void	sort_rest(t_stack **stack_a, t_stack **stack_b)
{
	t_utils	*utils;

	utils = (t_utils *)malloc(sizeof(t_utils));
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (len_stack(*stack_a) > 3)
		push_a_to_b(stack_a, stack_b, utils);
	sort_3(stack_a);
	while (len_stack(*stack_b) > 0)
		push_b_to_a(stack_a, stack_b, utils);
	final_rotate(stack_a);
	free (utils);
}
