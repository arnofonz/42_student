/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:29:49 by afontan           #+#    #+#             */
/*   Updated: 2025/01/29 11:12:19 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_error(int error_nb)
{
	if (error_nb == 11)
		ft_putstr_fd("ERROR : Not enclosed by walls\n", 2);
	if (error_nb == 12)
		ft_putstr_fd("ERROR : map too small\n", 2);
	if (error_nb == 13)
		ft_putstr_fd("ERROR : Irregular map width\n", 2);
	if (error_nb == 14)
		ft_putstr_fd("ERROR : bad character\n", 2);
	if (error_nb == 15)
		ft_putstr_fd("ERROR : nb of item/coll/player\n", 2);
	return (-1);
}
