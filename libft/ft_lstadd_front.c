/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:22:46 by afontan           #+#    #+#             */
/*   Updated: 2024/11/11 17:29:06 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void ft_lstadd_front(t_list **lst, t_list *new)
{
	if(lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}

/* 
int main(void)
{
	t_list *list = NULL;
	
	
    ft_lstadd_front(&list, ft_lstnew(" ! "));
    ft_lstadd_front(&list, ft_lstnew(" World"));
    ft_lstadd_front(&list, ft_lstnew("Hello"));


	while (list)
	{
		printf("%s", (char *)list -> content);
		list = list ->next;
	}
} */