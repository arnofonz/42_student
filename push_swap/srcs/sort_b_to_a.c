/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:22:42 by afontan           #+#    #+#             */
/*   Updated: 2025/01/13 11:33:00 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**========================================================================
 * Outils de rotation pour les 2 sens (les 2 fonctions suivantes) B -> A
 *========================================================================**/

void	rot_back_two(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
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

void	rot_back_one(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
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
	rot_back_two(stack_a, stack_b, utils);
}

/**========================================================================
 * Calcul du coup des op pour passer de stack B a stack A (retour)
 *========================================================================**/

void	rotate_b_to_a(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
{
	utils->target_a = targ_ret(utils->best_index_b, stack_a);
	utils->target_b = targ_ret(utils->best_index_b, stack_b);
	if ((check_pos(stack_a, utils->target_a)) <= (len_stack(*stack_a) / 2))
	{
		utils->cost_a = ver_pos(stack_a, utils->target_a);
		utils->rcost_a = 0;
	}
	else
	{
		utils->cost_a = 0;
		utils->rcost_a = ver_pos(stack_a, utils->target_a);
	}
	if ((check_pos(stack_b, utils->target_b)) <= (len_stack(*stack_b) / 2))
	{
		utils->cost_b = ver_pos(stack_b, utils->best_index_b);
		utils->rcost_b = 0;
	}
	else
	{
		utils->cost_b = 0;
		utils->rcost_b = ver_pos(stack_b, utils->best_index_b);
	}
	rot_back_one(stack_a, stack_b, utils);
}
/**========================================================================
 *                           Premiere fonction B to A
 *========================================================================**/

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b, t_utils *utils)
{
	t_stack	*check_b;

	check_b = *stack_b;
	utils->cost_b = ver_pos(stack_b, check_b->index);
	utils->cost_a = ver_pos(stack_a, targ_ret(check_b->index, stack_a));
	utils->cost_total = utils->cost_a + utils->cost_b;
	if (utils->cost_total == 0)
	{
		pa(stack_a, stack_b);
		return ;
	}
	utils->best_index_b = check_b->index;
	while (check_b != NULL)
	{
		utils->cost_b = ver_pos(stack_b, check_b->index);
		utils->cost_a = ver_pos(stack_a, targ_ret(check_b->index, stack_a));
		if (utils->cost_total > utils->cost_a + utils->cost_b)
		{
			utils->cost_total = utils->cost_a + utils->cost_b;
			utils->best_index_b = check_b->index;
		}
		check_b = check_b ->next;
	}
	rotate_b_to_a(stack_a, stack_b, utils);
	pa(stack_a, stack_b);
}
