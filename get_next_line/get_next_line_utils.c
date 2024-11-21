/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:17:35 by afontan           #+#    #+#             */
/*   Updated: 2024/11/21 14:06:29 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nitem, size_t size)
{
	void	*ptr;
	size_t	sizetotal;
	
	sizetotal = nitem * size;
	if (nitem != 0 && sizetotal / nitem != size)
		return (NULL);
	ptr = (void *)malloc(sizetotal);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitem * size);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = "";
	dest = ft_calloc(1, ft_strlen(s1) + BUFFER_SIZE + 1);
	if (!dest)
	{
		free (dest);
		return (NULL);
	}
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}



int	ft_strchr(const char *str, int c)
{
	int	i;

	 if (str == NULL) 
        return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (2);
	return (0);
}