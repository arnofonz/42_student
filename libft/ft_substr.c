/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:03:15 by afontan           #+#    #+#             */
/*   Updated: 2024/11/12 18:00:22 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
	{
		s2 = malloc(1);
		if (!s2)
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	if (len > size - start)
		len = size - start;
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, &s[start], len + 1);
	return (s2);
}

/* 
int main(void)
{
	char *str = "";
	unsigned int start = 20;
	size_t len;
	char *dst;

	len = ft_strlen(str);
	dst = ft_substr(str, start, len);
	printf("%zu\n", len);
	printf("%s", ft_substr(str, start, len));
	
}  */