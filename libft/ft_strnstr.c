/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:16:31 by afontan           #+#    #+#             */
/*   Updated: 2024/11/06 10:06:16 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] != '\0' && (i + j) < n)
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}

/* 
int main(void)
{
	const char *s1 = "hello world!";
	const char *s2 = "lo";
	size_t n = 5;
	
	printf("%s", ft_strnstr(s1, s2, n));
	
}
 */