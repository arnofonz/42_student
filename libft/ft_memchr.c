/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:10:59 by afontan           #+#    #+#             */
/*   Updated: 2024/11/05 14:55:26 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/* 
int main(void)
{
	char *str = NULL;
	size_t n = 3;
	char c = 'w';
	
	printf("%s", ((char *)ft_memchr(str, c, n)));
} */