/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:47:26 by afontan           #+#    #+#             */
/*   Updated: 2024/11/12 13:38:50 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}

char	*testmalloc(int n)
{
	int		i;
	int		sign;
	char	*str;

	sign = 1;
	i = 0;
	if (n < 0)
		sign = -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (sign == -1)
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*str;

	i = 0;
	sign = 0;
	str = testmalloc(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (0);
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (n != 0)
	{
		str[i++] = n % 10 + 48;
		n = n / 10;
	}
	if (sign == 1)
		str[i] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
/* 

int main(void)
{
	int n = 648;

	//printf("%s", ft_strrev(str));
	printf("%s", ft_itoa(n));
}  */