/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:50:15 by afontan           #+#    #+#             */
/*   Updated: 2024/11/12 11:58:01 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(f)(lst -> content);
		lst = lst -> next;
	}	
}

/* 
void	ft_toupperstr(void *content)
{
	int i;
	char *str = (char *)content;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
}


int main(void)
{
	t_list *lst = NULL;

	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("hello")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("world")));


	ft_lstiter(lst, ft_toupperstr);
	
	while(lst)
	{
		printf("%s", (char *)lst -> content);
		lst = lst -> next;
	}

}
 */