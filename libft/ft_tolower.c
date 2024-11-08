/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:15:08 by afontan           #+#    #+#             */
/*   Updated: 2024/11/05 13:44:24 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/* 
#include <stdio.h>
#include <unistd.h>
int main(void)
{
	char c = 'X';
	
	printf("%d\n", c);
	printf("%d", ft_tolower(c));
} */