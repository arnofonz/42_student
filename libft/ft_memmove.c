/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:04:07 by afontan           #+#    #+#             */
/*   Updated: 2024/11/05 09:54:25 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*dest;

	tmp = (char *)src;
	dest = (char *)dst;
	i = 0;
	if (tmp < dest)
	{
		while (n > 0)
		{
			dest[n] = tmp[n];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			dest[i] = tmp [i];
			i++;
		}
	}
	return (dst);
}

// #include <stdio.h>
// int main(void)
// {
//     size_t n = 5;
//     char src[] = "hello";
//     char dst[4];
//     ft_memmove(dst, src, n);
//     printf("%s", dst);
// }