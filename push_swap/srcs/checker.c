/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:33:25 by afontan           #+#    #+#             */
/*   Updated: 2025/01/10 18:32:43 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s2, const char *s1)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	prompt_instructions(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	get_instruction(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		if ((prompt_instructions(stack_a, stack_b, line)) == 0)
		{
			ft_printf("Error\n");
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	check_and_do(t_stack **stack_a, t_stack **stack_b)
{
	if (!get_instruction(stack_a, stack_b))
		return (0);
	if (!ft_lstcmp(stack_a))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (is_tried(*stack_a) == 1)
		ft_putstr("OK");
	else
		ft_putstr("KO");
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		nb_arg;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		nb_arg = initialize_stack(&stack_a, av[1]);
	else if (ac > 2)
		nb_arg = initiailize_arg(&stack_a, ac, av);
	if (nb_arg < 0)
		ft_printf("Error");
	check_and_do(&stack_a, &stack_b);
	ft_stack_clear(&stack_a, del);
	ft_stack_clear(&stack_b, del);
	return (0);
}