/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:17:35 by afontan           #+#    #+#             */
/*   Updated: 2025/01/10 16:49:42 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char const *s1, char *s2)
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
	return (dest[i + j] = '\0', dest);
}

int	ft_strchr_gnl(const char *str, int c)
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
