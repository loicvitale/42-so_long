/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:45:18 by lvitale           #+#    #+#             */
/*   Updated: 2024/01/15 10:42:28 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontalwall(t_complete *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->heightmap)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (y == game->heightmap - 1 || y == 0)
			{
				if (game->map[y][x] != '1' && game->map[y][x] != '\n')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	verticalwall(t_complete *game)
{
	int	y;
	int	x;

	y = 0;
	x = game->widthmap;
	while (y < game->heightmap)
	{
		if (!(game->map[y][0] == '1' 
			&& game->map[y][x - 1] == '1'))
			return (0);
		y++;
	}
	return (1);
}

static void	if_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
		exit_point(game, "Error\nThe map must be surrounded by  a wall\n", 1);
}

void	count_checker(t_complete *game, int y, int x)
{
	if (game->map[y][x] != '1' &&
		game->map[y][x] != '0' &&
		game->map[y][x] != 'P' &&
		game->map[y][x] != 'E' &&
		game->map[y][x] != 'C' &&
		game->map[y][x] != '\n')
	{
		exit_point(game, "Error\nUnknow symbol\n", 1);
	}
	if (game->map[y][x] == 'C')
		game->columncount++;
	if (game->map[y][x] == 'P')
		game->playercount++;
	if (game->map[y][x] == 'E')
	{
		game->exitcount++;
		game->exitpos_x = x;
		game->exitpos_y = y;
	}
}

void	check_errors(t_complete *game)
{
	if (game->widthmap == game->heightmap)
		exit_point(game, "Error\nThe map must be rectangular\n", 1);
	if_walls(game);
	character_valid(game);
	valid_path(game);
}
