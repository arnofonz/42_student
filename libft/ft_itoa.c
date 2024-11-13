/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:47:26 by afontan           #+#    #+#             */
/*   Updated: 2024/11/13 09:19:14 by afontan          ###   ########.fr       */
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

int	ft_sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

char	*testmalloc(int n)
{
	int		i;
	int		sign;
	char	*str;

	sign = ft_sign(n);
	i = 0;
	if (n == 0)
	{
		str = malloc(2);
		return (str);
	}
	if (n < 0)
		n = -n;
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
	sign = ft_sign(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = testmalloc(n);
	if (n == 0)
	{
		str[0] = '0';
		i++;
	}
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		str[i++] = n % 10 + 48;
		n = n / 10;
	}
	if (sign == -1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

/* 
int main(void)
{
	int n = 0;
	printf("%s", ft_itoa(n));
}    */