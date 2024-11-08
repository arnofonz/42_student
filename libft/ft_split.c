/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:39:37 by afontan           #+#    #+#             */
/*   Updated: 2024/11/07 13:55:22 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countwords(const char *str, char c)
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

char	**ft_split(char const *s, char c)
{
	char	**tab_str;
	size_t	i;
	size_t	j;
	int		tab;

	i = 0;
	tab = 0;
	tab_str = malloc (((countwords(s, c)) + 1) * sizeof(char *));
	if (!tab_str)
		return (NULL);
	while (s[i])
	{
		j = i;
		while (s[i++] == c && s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] != '\0')
			tab_str[tab++] = ft_substr(s, j, i - j);
	}
	if (s[i] == '\0' && s[i - 1] != c)
		tab_str[tab++] = ft_substr(s, j, i - j);
	tab_str[tab] = NULL;
	return (tab_str);
}

/* 
int main(void)
{
	int i = 0;
	const char *str = "      hello     les   copains    iii";
	char c = ' ';
	char **strstr;

	printf("%d\n", countwords(str, c));
	strstr = ft_split(str, c);
	while (strstr[i] != NULL)
	{
		printf("%s\n", strstr[i]);
		i++;
	 }
	
} */