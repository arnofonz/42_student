/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:43:10 by afontan           #+#    #+#             */
/*   Updated: 2024/11/21 16:43:25 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1 || BUFFER_SIZE > 8000000
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 10
#  endif
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char *s2);
int		ft_strchr(const char *str, int c);
char	*cpy_line(char *str);
char	*stock_end(char *str);
int		ft_strlen(const char *str);
void	*ft_calloc(size_t nitem, size_t size);
void	ft_bzero(void *s, size_t n);

#endif