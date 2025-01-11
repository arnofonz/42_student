/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:18:43 by afontan           #+#    #+#             */
/*   Updated: 2025/01/10 17:58:52 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*back;
}	t_stack;

typedef struct s_utils
{
	int	cost_a;
	int	cost_b;
	int	rcost_a;
	int	rcost_b;
	int	cost_total;
	int	best_index_a;
	int	best_index_b;
	int	target_a;
	int	target_b;
}	t_utils;

/**========================================================================
 *                               Utils node
 *========================================================================**/
void	swap_arg(t_stack *stack);
void	my_push_back(t_stack **stack_a, int new_value, int new_index);
t_stack	*my_lstnew(int new_value, int new_index);
void	my_push_front(t_stack **stack, int new_value, int new_index);
void	del(t_stack *node);
int		ft_lstcmp(t_stack **stack_a);
void	ft_stack_clear(t_stack **lst, void (*del)(t_stack *));

/**========================================================================
 *                               Initialize
 *========================================================================**/

int		initialize_stack(t_stack **stack_a, char *str);
int		initiailize_arg(t_stack **stack_a, int ac, char **av);
void	initialize_index(t_stack **stack_a, int max);

/**========================================================================
 *                                 Check
 *========================================================================**/
int		check_min(t_stack **stack, int index);
int		check_max(t_stack **stack, int index);
int		check_pos(t_stack **stack, int to_find);

/**========================================================================
 *                                 Mooves
 *========================================================================**/
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_a);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_a);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/**========================================================================
 *                              Sort 2 to 5
 *========================================================================**/
void	sort_2_to_5(t_stack **stack_a, t_stack **stack_b, int nb);
void	sort_2(t_stack **stack_a);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

/**========================================================================
 *                              Sort A to B
 *========================================================================**/
void	rot_first_two(t_stack **stack_a, t_stack **stack_b, t_utils *utils);
void	rot_first_one(t_stack **stack_a, t_stack **stack_b, t_utils *utils);
void	rotate_a_to_b(t_stack **stack_a, t_stack **stack_b, t_utils *utils);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, t_utils *utils);

/**========================================================================
 *                              Sort B to A
 *========================================================================**/
void	rot_back_two(t_stack **stack_a, t_stack **stack_b, t_utils *utils);
void	rot_back_one(t_stack **stack_a, t_stack **stack_b, t_utils *utils);
void	rotate_b_to_a(t_stack **stack_a, t_stack **stack_b, t_utils *utils);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b, t_utils *utils);

/**========================================================================
 *                           Algo et utils algo
 *========================================================================**/
int		ver_pos(t_stack **stack, int to_find);
int		targ_ret(int index_a, t_stack **stack_b);
int		verif_targ(int index_a, t_stack **stack_b);
void	final_rotate(t_stack **stack_a);
void	sort_rest(t_stack **stack_a, t_stack **stack_b);

/**========================================================================
 *                                  Utils
 *========================================================================**/
int		find_min(t_stack **stack);
int		find_max(t_stack **stack);
int		ft_isnum(char *str);
int		is_min(t_stack **stack_a);
int		len_stack(t_stack *stack);
void	ft_sort_int_tab(int *tab, unsigned int size);
void	print_stack(t_stack *stack_a, t_stack *stack_b);
long	ft_atoi_ps(const char *str);
void	copy_nbr(t_stack **stack_a, int *tab, int max);
int		is_tried(t_stack *stack);

#endif
