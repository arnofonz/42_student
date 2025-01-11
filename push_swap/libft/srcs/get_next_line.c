/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:31:35 by afontan           #+#    #+#             */
/*   Updated: 2025/01/10 17:55:51 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cpy_line(char *str)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	len++;
	dest = ft_calloc(1, len + 1);
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*stock_end(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	dest = ft_calloc(1, ft_strlen(str) - i + 1);
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
		dest[j++] = str[i++];
	free(str);
	return (dest);
}

char	*read_and_join(int fd, char *tmp)
{
	char		*buffer;
	char		*temp;
	ssize_t		size_read;

	size_read = 1;
	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr_gnl(tmp, '\n') != 1 && size_read > 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read < 0 || (size_read == 0 && tmp == NULL))
		{
			free (buffer);
			free (tmp);
			return (NULL);
		}
		buffer[size_read] = '\0';
		temp = tmp;
		tmp = ft_strjoin_gnl(tmp, buffer);
		if (temp)
			free (temp);
	}
	free (buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp[fd] = read_and_join(fd, tmp[fd]);
	if (!tmp[fd] || tmp[fd][0] == '\0')
	{
		free (tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	line = cpy_line(tmp[fd]);
	tmp[fd] = stock_end(tmp[fd]);
	return (line);
}

/* 

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char *str;
	//ssize_t rd_file;

	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	 	perror("Erreur lors de l'ouverture");
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	//get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);

	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = NULL;
	close(fd);
}  */