/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:13:32 by lvitale           #+#    #+#             */
/*   Updated: 2024/01/15 10:39:10 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	*start_pos(t_complete *game, char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = ft_calloc(2, sizeof(int));
	if (!(pos))
		exit_point(game, "Error\nMalloc failled\n", 1);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

static void	replace_map(t_complete *data, int y, int x, int *content)
{
	if (!(y < 1 || x < 1 || y >= data->heightmap || x >= data->widthmap
			|| data->map_2[y][x] == '1' || data->map_2[y][x] == 'X'))
	{
		if (data->map_2[y][x] == 'C')
			content[1]--;
		if (data->map_2[y][x] == 'E')
			content[0]--;
		data->map_2[y][x] = 'X';
		replace_map(data, y + 1, x, content);
		replace_map(data, y - 1, x, content);
		replace_map(data, y, x + 1, content);
		replace_map(data, y, x - 1, content);
	}
}

static char	**copy_map(t_complete *game)
{
	char	**map_2;
	int		y;
	int		x;

	y = 0;
	map_2 = ft_calloc(game->heightmap, sizeof(char *));
	if (!map_2)
		exit_point(game, "Error\nMalloc failled\n", 1);
	while (y < game->heightmap)
	{
		x = 0;
		map_2[y] = ft_calloc(game->widthmap, sizeof(char *));
		if (!(map_2[y]))
		{
			ft_freemap(game->map_2, game);
			exit_point(game, "Error\nMalloc failled\n", 1);
		}
		while (game->map[y][x])
		{
			map_2[y][x] = game->map[y][x];
			x++;
		}
		y++;
	}
	return (map_2);
}

void	valid_path(t_complete *game)
{
	int	*pos;
	int	*content;

	game->map_2 = ft_calloc(game->heightmap, sizeof(char *));
	if (!game->map_2)
		exit_point(game, "Error\nMalloc failled\n", 1);
	game->map_2 = copy_map(game);
	pos = start_pos(game, game->map);
	content = ft_calloc(2, sizeof(int));
	if (!content)
		exit_point(game, "Error\nMalloc failled\n", 1);
	content[0] = game->exitcount;
	content[1] = game->columncount;
	replace_map(game, pos[0], pos[1], content);
	if (!(content[0] == 0 && content[1] == 0))
	{
		free(pos);
		free(content);
		ft_freemap(game->map_2, game);
		exit_point(game, "Error\nNo possible path\n", 1);
	}
	free(pos);
	free(content);
	ft_freemap(game->map_2, game);
}
