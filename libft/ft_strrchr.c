/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:54:03 by afontan           #+#    #+#             */
/*   Updated: 2024/11/08 15:57:00 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	if (c == '\0')
		return ("\0");
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
/* 
int main(void)
{
	const char str[] = "hello world";
	char c = '\0';
	
	printf("%s", ft_strrchr(str, c));
} */