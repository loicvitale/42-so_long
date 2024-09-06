/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:46:06 by lvitale           #+#    #+#             */
/*   Updated: 2024/01/15 11:25:10 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "../minilibx/mlx.h"

# define WIDTH_IMG 50
# define HEIGHT_IMG 50
# define WIDTH_SCREEN 1440
# define HEIGTH_SCREEN 2560

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		exitpos_x;
	int		exitpos_y;
	int		counter;
	int		collectables;

	char	**map;
	char	**map_2;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

int		controls_working(int command, t_complete *game);

void	count_checker(t_complete *game, int y, int x);
void	check_errors(t_complete *game);

void	place_images_in_game(t_complete *game);
void	adding_in_graphics(t_complete *game);

int		map_reading(t_complete *game, char **argv);
void	character_valid(t_complete *game);

void	ft_freemap(char **map, t_complete *game);
int		exit_point(t_complete *game, char *str, int freemap);

void	valid_path(t_complete *data);

void	*ft_calloc(size_t count, size_t size);

#endif
