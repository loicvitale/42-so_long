/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:44:43 by lvitale           #+#    #+#             */
/*   Updated: 2024/01/15 10:18:38 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	n;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	n = count * size;
	while (n > 0)
	{
		((char *) tab)[n - 1] = 0;
		n--; 
	}
	return (tab);
}

void	ft_freemap(char **map, t_complete *game)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < game->heightmap && map[i])
			free(map[i++]);
	}
	free(map);
	map = NULL;
}

int	exit_point(t_complete *game, char *str, int freemap)
{
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	if (freemap)
		ft_freemap(game->map, game);
	if (ft_strlen(str) > 0)
	{
		ft_printf(str);
		exit(1);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
	{
		ft_printf("Error\nEnter 1 argument (.ber)\n");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_complete));
	map_reading(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * \
	WIDTH_IMG), (game.heightmap * HEIGHT_IMG), "so_long");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}
