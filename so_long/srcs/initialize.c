/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:46:21 by afontan           #+#    #+#             */
/*   Updated: 2025/01/29 09:46:08 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_collectible(t_start *start)
{
	int	i;
	int	j;

	i = 0;
	start->collectible = 0;
	while (i < start->h_map)
	{
		j = 0;
		while (j < start->l_map)
		{
			if (start->map[i][j] == 'C')
				start->collectible ++;
			j++;
		}
		i++;
	}
}

void	count_line(const char *file, t_start *start)
{
	char	*line;
	int		fd;
	char	buffer[1];

	start->h_map = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if ((fd < 0) || (read(fd, buffer, 0) == -1) || line == NULL)
	{
		perror("Error");
		close (fd);
		mlx_destroy_display(start->mlx);
		free(start->mlx);
		free(start);
		exit(1);
	}
	while (line != NULL)
	{
		free(line);
		line = NULL;
		start->h_map++;
		line = get_next_line(fd);
	}
	close (fd);
}

int	read_map(const char *file, t_start *start)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	count_line(file, start);
	start->map = ft_calloc(1, (start->h_map + 1) * sizeof(char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = (get_next_line(fd));
	while (line != NULL)
	{
		start->map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
		line = (get_next_line(fd));
	}
	start->l_map = ft_strlen(start->map[0]) - 1;
	start->fd = fd;
	if (map_is_valid(start) == -1)
		return (0);
	return (1);
}

void	initialize_img(t_start *start)
{
	start->wall = mlx_xpm_file_to_image(start->mlx,
			"xpm/tribune.xpm", &start->width, &start->height);
	start->found = mlx_xpm_file_to_image(start->mlx,
			"xpm/texture-sol.xpm", &start->width, &start->height);
	start->cage = mlx_xpm_file_to_image(start->mlx,
			"xpm/cage_gardien.xpm", &start->width, &start->height);
	start->player = mlx_xpm_file_to_image(start->mlx,
			"xpm/joueur.xpm", &start->width, &start->height);
	start->ball = mlx_xpm_file_to_image(start->mlx,
			"xpm/ballon.xpm", &start->width, &start->height);
	start->cage_v = mlx_xpm_file_to_image(start->mlx,
			"xpm/cage_vide.xpm", &start->width, &start->height);
}

int	initialize_win_and_mlx(char **av, t_start *start)
{
	start->width = 64;
	start->height = 64;
	start->cage = NULL;
	start->player = NULL;
	start->ball = NULL;
	start->mlx = mlx_init();
	if (!start->mlx)
		return (-1);
	if ((read_map(av[1], start)) == 0)
		return (-1);
	start->win = mlx_new_window(start->mlx, start->l_map * start->width,
			start->h_map * start->width, "so_long");
	if (!start->win)
	{
		mlx_destroy_display(start->mlx);
		free(start->mlx);
		return (-1);
	}
	initialize_img(start);
	draw_map(start);
	if (!start->wall || !start->found || !start->cage
		|| !start->player || !start->ball)
		return (-1);
	return (0);
}
