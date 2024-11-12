/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:05:21 by afontan           #+#    #+#             */
/*   Updated: 2024/11/12 12:02:36 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *content)
{
	free(content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)-> next;
		del ((*lst)-> content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

/* 
int main(void)
{
	t_list *lst = NULL;

	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("hello")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup(" world")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup(" bye")));



	printf("%d\n", ft_lstsize(lst));
	ft_lstclear(&lst, del);
	printf("%d", ft_lstsize(lst));
	
} */