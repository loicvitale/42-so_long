/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:45:10 by lvitale           #+#    #+#             */
/*   Updated: 2024/01/15 10:40:08 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_player(t_complete *game, int y, int x)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, x * WIDTH_IMG, y * HEIGHT_IMG);
	game->y_axis = y;
	game->x_axis = x;
}

static void	place_collectable(t_complete *game, int y, int x)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, x * WIDTH_IMG, y * HEIGHT_IMG);
	game->collectables++;
}

static void	place_exit_wall_floor(t_complete *game, int y, int x)
{
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, x * WIDTH_IMG, y * HEIGHT_IMG);
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, x * WIDTH_IMG, y * HEIGHT_IMG);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->barrier, x * WIDTH_IMG, y * HEIGHT_IMG);
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/item.xpm", &i, &j);
	if (game->floor == 0 || game->barrier == 0 || game->player == 0 || \
		game->exit == 0 || game->collectable == 0)
		exit_point(game, "Error\nTexture doesn't load\n", 1);
}

void	adding_in_graphics(t_complete *game)
{
	int	y;
	int	x;

	game->collectables = 0;
	y = 0;
	while (y < game->heightmap)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				place_collectable(game, y, x);
			if (game->map[y][x] == 'P')
				place_player(game, y, x);
			if (game->map[y][x] == 'E'
				|| game->map[y][x] == '0'
				|| game->map[y][x] == '1')
				place_exit_wall_floor(game, y, x);
			x++;
		}
		y++;
	}
}
