/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:45:11 by afontan           #+#    #+#             */
/*   Updated: 2024/11/06 10:08:09 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	sdest;
	size_t	ssrc;

	i = 0;
	sdest = ft_strlen(dest);
	ssrc = ft_strlen(src);
	if (size <= sdest)
		return (size + ssrc);
	while (src[i] && ((sdest + i) < (size - 1)))
	{
		dest[sdest + i] = src[i];
		i++;
	}
	dest[sdest + i] = '\0';
	return (sdest + ssrc);
}

/* 
int main(void)
{
	char dest[20] = "hello";
	const char *src = "world";
	size_t size = 0;

	printf("%ld \n", ft_strlcat(dest, src, size));

	printf("%s", dest);
} */