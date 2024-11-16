/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:38:18 by afontan           #+#    #+#             */
/*   Updated: 2024/11/13 15:18:07 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitem, size_t size)
{
	void	*ptr;

	ptr = malloc(nitem * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitem * size);
	return (ptr);
}
