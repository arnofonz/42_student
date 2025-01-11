/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:36:24 by afontan           #+#    #+#             */
/*   Updated: 2025/01/10 18:19:13 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curent_a;
	t_stack	*curent_b;

	curent_a = stack_a;
	curent_b = stack_b;
	ft_printf("%s\n", "Pile A\t\tPile B\n");
	while (curent_a != NULL || curent_b != NULL)
	{
		if (curent_a != NULL)
		{
			ft_printf("%d", curent_a ->value);
			ft_printf(" - index : %d", curent_a -> index);
			curent_a = curent_a ->next;
		}
		else
			ft_printf(" ");
		if (curent_b != NULL)
		{
			ft_printf("\t\t%d\n", curent_b ->index);
			curent_b = curent_b ->next;
		}
		else
			ft_printf(" \n");
	}
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
	if (nb_arg == 0)
		return (0);
	if (nb_arg < 0)
		return (ft_putstr("Error \n"));
	else if (is_tried(stack_a) == 1)
		return (0);
	else if (nb_arg <= 5)
		sort_2_to_5(&stack_a, &stack_b, nb_arg);
	else
		sort_rest(&stack_a, &stack_b);
	ft_stack_clear(&stack_a, del);
	ft_stack_clear(&stack_b, del);
	return (0);
}
	//ft_printf("is tried : %d\n", is_tried(stack_a));

	//print_stack(stack_a, stack_b);
	//ft_printf("pos min: %d\n", is_min(stack_a));
	//ft_printf("len stack: %d\n", len_stack(stack_a));