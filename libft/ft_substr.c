/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:03:15 by afontan           #+#    #+#             */
/*   Updated: 2024/11/08 10:54:18 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	int		size;

	size = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)size)
		return (malloc(1));
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		s2[i] = s[start];
		i++;
		start ++;
	}
	s2[i] = '\0';
	return (s2);
}

/* 
int main(void)
{
	char *str = "hello world !!!";
	unsigned int start = 20;
	size_t len;
	char *dst;

	len = ft_strlen(str);
	dst = ft_substr(str, start, len);
	printf("%zu\n", len);
	printf("%s", ft_substr(str, start, len));
	
} */