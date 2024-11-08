/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:15:48 by afontan           #+#    #+#             */
/*   Updated: 2024/11/08 10:35:44 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	dest = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	return (dest);
}

/* 
char	ft_touper(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
int main(void)
{
	char str[] = "hello";
	char *dest;

	dest = ft_strmapi(str, ft_touper);
	printf("%s",dest);
	
} */