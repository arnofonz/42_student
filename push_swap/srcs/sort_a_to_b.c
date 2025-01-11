/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:11:32 by afontan           #+#    #+#             */
/*   Updated: 2025/01/09 14:14:34 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**========================================================================
 * Outils de rotation pour les 2 sens (les 2 fonctions suivantes) A -> B
 *========================================================================**/

void	rot_first_two(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
{
	while (utils->rcost_a)
	{
		rra(stack_a);
		utils->rcost_a--;
	}
	while (utils->rcost_b)
	{
		rrb(stack_b);
		utils->rcost_b--;
	}
}

void	rot_first_one(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
{
	while (utils->cost_a && utils->cost_b)
	{
		rr(stack_a, stack_b);
		utils->cost_a--;
		utils->cost_b--;
	}
	while (utils->rcost_a && utils->rcost_b)
	{
		rrr(stack_a, stack_b);
		utils->rcost_a--;
		utils->rcost_b--;
	}
	while (utils->cost_a)
	{
		ra(stack_a);
		utils->cost_a--;
	}
	while (utils->cost_b)
	{
		rb(stack_b);
		utils->cost_b--;
	}
	rot_first_two(stack_a, stack_b, utils);
}

/**========================================================================
 *      Calcul du coup des op pour passer de stack A a stack B 
 *========================================================================**/

void	rotate_a_to_b(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
{
	if ((check_pos(stack_a, utils->best_index_a))
		<= (len_stack(*stack_a) / 2))
	{
		utils->cost_a = ver_pos(stack_a, utils->best_index_a);
		utils->rcost_a = 0;
	}
	else
	{
		utils->cost_a = 0;
		utils->rcost_a = ver_pos(stack_a, utils->best_index_a);
	}
	if ((check_pos(stack_b, verif_targ(utils->best_index_a, stack_b)))
		<= (len_stack(*stack_b) / 2))
	{
		utils->cost_b
			= ver_pos(stack_b, verif_targ(utils->best_index_a, stack_b));
		utils->rcost_b = 0;
	}
	else
	{
		utils->cost_b = 0;
		utils->rcost_b
			= ver_pos(stack_b, verif_targ(utils->best_index_a, stack_b));
	}
	rot_first_one(stack_a, stack_b, utils);
}

/**========================================================================
 *                           Premiere fonction A to B
 *========================================================================**/

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
{
	t_stack	*check_a;

	check_a = *stack_a;
	utils->cost_a = ver_pos(stack_a, check_a->index);
	utils->cost_b = ver_pos(stack_b, verif_targ(check_a->index, stack_b));
	utils->cost_total = utils->cost_a + utils->cost_b;
	if (utils->cost_total == 0)
	{
		pb(stack_a, stack_b);
		return ;
	}
	utils->best_index_a = check_a->index;
	while (check_a != NULL)
	{
		utils->cost_a = ver_pos(stack_a, check_a->index);
		utils->cost_b = ver_pos(stack_b, verif_targ(check_a->index, stack_b));
		if (utils->cost_total > utils->cost_a + utils->cost_b)
		{
			utils->cost_total = utils->cost_a + utils->cost_b;
			utils->best_index_a = check_a->index;
		}
		check_a = check_a ->next;
	}
	rotate_a_to_b(stack_a, stack_b, utils);
	pb(stack_a, stack_b);
}
