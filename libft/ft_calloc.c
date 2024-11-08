/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:38:18 by afontan           #+#    #+#             */
/*   Updated: 2024/11/07 13:42:29 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitem, size_t size)
{
	void	*ptr;

	if (nitem == 0 || size == 0)
		return (NULL);
	ptr = malloc(nitem * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitem * size);
	return (ptr);
}
