/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:26:35 by afontan           #+#    #+#             */
/*   Updated: 2025/01/29 11:19:38 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "../mlx/mlx.h" 

# define UP    0
# define DOWN  1
# define LEFT  2
# define RIGHT 3

typedef struct s_point
{
	int	x;
	int	y;
	int	new_x;
	int	new_y;
}	t_point;

typedef struct s_start
{
	void	*ball;
	void	*cage;
	void	*cage_v;
	void	*player;
	void	*wall;
	void	*found;
	void	*mlx;
	void	*win;
	int		moves;
	int		width;
	int		height;
	int		h_map;
	int		l_map;
	int		error;
	int		test;
	int		check_e;
	int		check_c;
	int		total_col;
	int		collectible;
	int		index_c;
	int		fd;
	char	**map;
}	t_start;

/**========================================================================
 *                              Initialisation
 *========================================================================**/

void	draw_map(t_start *start);
int		initialize_win_and_mlx(char **av, t_start *start);
int		read_map(const char *file, t_start *start);
void	count_line(const char *file, t_start *start);
void	put_on_mlx(t_start *start, void *img, int x, int y);
void	draw_map_suite(t_start *start, int x, int y);
void	draw_map(t_start *start);
void	check_collectible(t_start *start);
int		is_valid(t_start *start, int x, int y);
int		is_error(int error_nb);

/**========================================================================
 *                              Close program
 *========================================================================**/

int		close_window(int keycode, t_start *start);
int		close_cross(t_start *start);
void	free_map(t_start *start);
void	free_all(t_start *start);

/**========================================================================
 *                           Check if map is valid
 *========================================================================**/

int		map_is_valid(t_start *start);
int		check_connectivity(t_start *start);
int		is_valid_c(t_start *start, int x, int y);
int		is_valid_e(t_start *start, int x, int y);
void	flood_fill_c(t_start *start, int x, int y, int **visited);
void	flood_fill_e(t_start *start, int x, int y, int **visited);
int		final_check(t_start *start, t_point *pt, int **visited);
void	reset_visited(t_start *start, int **visited);
void	check_collectible_c(t_start *start);
void	reset_visited(t_start *start, int **visited);
void	free_visited(t_start *start, int **visited);
void	pos_player(t_start *start, t_point **pt);

/**========================================================================
 *                                Moves Player
 *========================================================================**/

int		key_hook(int keycode, t_start *start);
int		is_valid_move(t_start *start, int x, int y);
void	moove_up(t_start *start, t_point *pos, int type);
void	moove_down(t_start *start, t_point *pos, int type);
void	moove_left(t_start *start, t_point *pos, int type);
void	moove_right(t_start *start, t_point *pos, int type);
void	do_moves(t_start *start, t_point *pos, int dir);

#endif