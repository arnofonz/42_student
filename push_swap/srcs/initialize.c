/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:35:11 by afontan           #+#    #+#             */
/*   Updated: 2025/01/21 10:42:00 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_index(t_stack **stack_a, int max)
{
	int		i;
	int		*tab;
	t_stack	*curent;

	i = 0;
	tab = ft_calloc(1, max * sizeof(int));
	curent = *stack_a;
	while (i < max)
	{
		tab[i++] = curent->value;
		curent = curent->next;
	}
	ft_sort_int_tab(tab, max);
	copy_nbr(stack_a, tab, max);
	free(tab);
}

int	initiailize_arg(t_stack **stack_a, int ac, char **av)
{
	int		i;
	long	num;

	i = 1;
	while (i < ac)
	{
		if (!ft_isnum(av[i]))
			return (-1);
		num = ft_atoi_ps(av[i], 0);
		if (num < -2147483648 || num > INT_MAX)
			return (-1);
		my_push_back(stack_a, ft_atoi(av[i]), 0);
		i++;
	}
	if (!ft_lstcmp(stack_a))
		return (-1);
	initialize_index(stack_a, ac - 1);
	return (ac - 1);
}

long	verif_error_str(char*str)
{
	int		i;
	long	x;

	i = 0;
	x = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		x = x * 10;
		x = x + str[i] - 48;
		i++;
	}
	if (str[i] != '\0')
		return (0);
	else
		return (x);
}

int	include_in_stack(t_stack **stack_a, char *str, int i, int sign)
{
	long	x;

	while (str[i])
	{
		x = 0;
		while (str[i] == ' ' && str[i])
			i++;
		while (str[i] != ' ' && str[i])
		{
			if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
				return (-1);
			if (str[i] == '-')
			{
				if ((str[i + 1] == ' '))
					return (-1);
				sign = -1;
				i++;
			}
			x = x * 10 + str[i++] - 48;
			if (x < -2147483648 || x > INT_MAX)
				return (-1);
		}
		my_push_back(stack_a, x * sign, 0);
	}
	return (0);
}

int	initialize_stack(t_stack **stack_a, char *str)
{
	if (verif_error_str(str) != 0 && verif_error_str(str) <= INT_MAX)
		return (0);
	else if (verif_error_str(str) < -2147483648
		|| verif_error_str(str) > INT_MAX)
		return (-1);
	if (include_in_stack(stack_a, str, 0, 1) == -1)
		return (-1);
	if (!ft_lstcmp(stack_a))
		return (-1);
	return (len_stack(*stack_a));
}
