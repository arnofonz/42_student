/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:49:05 by afontan           #+#    #+#             */
/*   Updated: 2024/11/05 09:52:49 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
/* 
#include <stdio.h>

int main(void)
{
	char str[10];
	size_t n = 10;
	int i = 0;

	ft_bzero(str, n);
	
	while (str[i])
	{
		printf("%d", str[i]);
		i++;
	}
} */