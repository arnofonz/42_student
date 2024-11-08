/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:55:35 by afontan           #+#    #+#             */
/*   Updated: 2024/11/06 10:07:10 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dst;
	int		size;

	i = 0;
	size = ft_strlen(src) + 1;
	dst = malloc(size * sizeof(char));
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* 
int main(void)
{
	char *str = "hello world";
	//char src[50];
	printf("%s", ft_strdup(str));
} */