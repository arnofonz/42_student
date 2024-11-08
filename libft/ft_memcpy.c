/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:54 by afontan           #+#    #+#             */
/*   Updated: 2024/11/05 09:55:53 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/* 
#include <stdio.h>

int main(void)
{
	char *src;
	char dest[25];
	
	src = "hello";

	size_t n = 5;
	int i = 0;

	ft_memcpy(dest, src, n);
	

		printf("%s", dest);
	

}  */