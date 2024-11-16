/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:39:37 by afontan           #+#    #+#             */
/*   Updated: 2024/11/15 10:25:21 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == c)
		count = -1;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count ++;
		i++;
	}
	if (str[i - 1] != c)
		count ++;
	return (count);
}

static void	free_malloc(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**write_split(char **tab_str, const char *s, char c, int tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = i;
		while (s[i++] == c && s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] != '\0' || (s[i] == '\0' && s[i - 1] != c))
		{
			tab_str[tab] = ft_substr(s, j, i - j);
			if (!tab_str[tab])
			{
				free_malloc(tab_str, tab);
				return (NULL);
			}
			tab++;
		}
	}
	tab_str[tab] = NULL;
	return (tab_str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_str;
	int		tab;

	tab = 0;
	if (s[0] == '\0')
	{
		tab_str = malloc(sizeof(char *));
		tab_str[0] = NULL;
		return (tab_str);
	}
	tab_str = malloc (((countwords(s, c)) + 1) * sizeof(char *));
	if (!tab_str)
		return (NULL);
	tab_str = write_split(tab_str, s, c, tab);
	return (tab_str);
}
