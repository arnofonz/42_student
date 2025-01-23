/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolspf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:58:04 by afontan           #+#    #+#             */
/*   Updated: 2025/01/13 15:43:01 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printprc(void)
{
	ft_putchar_pf('%');
	ft_putchar_pf(' ');
	return (2);
}

int	ft_putstr_pf(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_ptrprintf(void *ptr)
{
	int	i;

	if (ptr == NULL)
	{
		ft_putstr_pf("(nil)");
		return (5);
	}
	ft_putstr_pf("0x");
	i = ft_long_putnbr((unsigned long)ptr);
	return (i + 2);
}

int	particular_case(int nb)
{
	if (nb == 0)
	{
		ft_putchar_pf('0');
		return (1);
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	return (0);
}
