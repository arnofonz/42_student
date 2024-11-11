/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:34:14 by afontan           #+#    #+#             */
/*   Updated: 2024/11/11 17:51:31 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	if(!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	lst;
	return (lst);
}

int main(void)
{
	t_list *list = NULL;
	t_list *last;
	
	
    ft_lstadd_front(&list, ft_lstnew(" ! "));
    ft_lstadd_front(&list, ft_lstnew(" World"));
    ft_lstadd_front(&list, ft_lstnew("Hello"));

	last = ft_lstlast(list);
	printf("%s", (char *)last -> content);

}