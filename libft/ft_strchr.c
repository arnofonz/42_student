/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:17:05 by afontan           #+#    #+#             */
/*   Updated: 2024/11/08 15:54:34 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ("\0");
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
/* 
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char ch = 'u';
	char *str = "hello world !";

	char *st;
	st = ft_strchr(str, ch);


	printf("%s", st);
	
} */