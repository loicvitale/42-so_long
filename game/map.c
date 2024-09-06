/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:45:01 by lvitale           #+#    #+#             */
/*   Updated: 2024/01/15 11:30:12 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = -1;
	game->heightmap++;
	if (game->heightmap * HEIGHT_IMG > WIDTH_SCREEN)
		exit_point(game, "Error\nHeight max\n", 1);
	temporary = ft_calloc(sizeof(char *), (game->heightmap + 1));
	if (!(temporary))
		exit_point(game, "Error\nMalloc failled\n", 1);
	temporary[game->heightmap] = NULL;
	while (++i < game->heightmap - 1)
		temporary[i] = game->map[i];
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	if (width_of_map(line) * WIDTH_IMG > HEIGTH_SCREEN)
		exit_point(game, "Error\nWidth max\n", 1);
	if (game->map[0] && width_of_map(game->map[0]) != width_of_map(line))
		exit_point(game, "Error\nThe map must be rectangular\n", 1);
	return (1);
}

static int	check_ext(char *str, char *ext)
{
	int	i;
	int	size_str;
	int	size_ext;

	size_str = ft_strlen(str);
	size_ext = ft_strlen(ext);
	i = 1;
	while (i <= size_ext)
	{
		if (str[size_str - i] != ext[size_ext - i])
			return (0);
		i++;
	}
	return (1);
}

void	character_valid(t_complete *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->heightmap - 1)
	{
		x = 0;
		while (x <= game->widthmap)
		{
			count_checker(game, y, x);
			x++;
		}
		y++;
	}
	if (!(game->playercount == 1 && game->columncount > 0
			&& game->exitcount == 1))
	{
		exit_point(game, "Error\nThe map must have 1 player, 1 \
exit and at least 1 item\n", 1);
	}
}

int	map_reading(t_complete *game, char **argv)
{
	char	*readmap;

	if (!(check_ext(argv[1], ".ber")))
		exit_point(game, "Error\nInvalid extension\n", 1);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		exit_point(game, "Error\nCannot be open\n", 1);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	if (!game->map)
		exit_point(game, "Error\nMap empty\n", 1);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
