/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:47:26 by afontan           #+#    #+#             */
/*   Updated: 2024/11/08 09:03:50 by afontan          ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*str;

	i = 0;
	sign = 0;
	str = malloc((12) * sizeof(char));
	if (n == 0)
		return (0);
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (n != 0)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i ++;
	}
	if (sign == 1)
		str[i] = '-';
	str[i + 1] = '\0';
	return (ft_strrev(str));
}

/* 

int main(void)
{
	int n = 4535434;

	//printf("%s", ft_strrev(str));
	printf("%s", ft_itoa(n));
} */