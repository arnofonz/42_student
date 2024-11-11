/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:29:47 by afontan           #+#    #+#             */
/*   Updated: 2024/11/11 16:54:18 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*new_ct;

	new_ct = (t_list *)malloc(sizeof(t_list));
	if (!new_ct)
	 return (NULL);
	new_ct -> content = content;
	new_ct -> next = NULL;
	return (new_ct);
}

/* 
int main(void)
{
	char *x = "hello world";
	t_list *new;

	new = ft_lstnew((char *)x);
	printf("%s", (char *)new -> content);
	free(new);
} */