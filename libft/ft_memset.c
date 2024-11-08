/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:37:31 by afontan           #+#    #+#             */
/*   Updated: 2024/11/05 09:51:00 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* 
#include <stdio.h>

int main(void)
{
	char str[10];
	int c = 1;
	size_t n = 10;
	int i = 0;

	ft_memset(str, c, n);
	
	while (str[i])
	{
		printf("%d", str[i]);
		i++;
	}
} */