/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitale <lvitale@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:45:24 by lvitale           #+#    #+#             */
/*   Updated: 2024/01/15 11:46:25 by lvitale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	right_move(t_complete *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectables != 0)
			game->map[y][x] = 'P';
		else
		{
			ft_printf("Count movement : %i\n", game->counter + 1);
			ft_printf("\nYou win, congratulation!\n");
			exit_point(game, "", 1);
		}
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->collectables--;
	}
	game->x_axis = x;
	game->y_axis = y;
	game->counter++;
	return (1);
}

static int	keyboard_w_s(t_complete *game, int movement, int x, int y)
{
	x = game->x_axis;
	y = game->y_axis;
	if (movement == 13)
	{
		y--;
		if (game->map[y][x] == '1' || !(right_move(game, x, y)))
			return (0);
		if (x == game->exitpos_x && y + 1 == game->exitpos_y)
			game->map[y + 1][x] = 'E';
		else
			game->map[y + 1][x] = '0';
	}
	else if (movement == 1)
	{
		y++;
		if (game->map[y][x] == '1' || !(right_move(game, x, y)))
			return (0);
		if (x == game->exitpos_x && y - 1 == game->exitpos_y)
			game->map[y - 1][x] = 'E';
		else
			game->map[y - 1][x] = '0';
	}
	ft_printf("Count movement : %i\n", game->counter);
	return (1);
}

static int	keyboard_a_d(t_complete *game, int movement, int x, int y)
{
	x = game->x_axis;
	y = game->y_axis;
	if (movement == 0)
	{
		x--;
		if (game->map[y][x] == '1' || !(right_move(game, x, y)))
			return (0);
		if (x + 1 == game->exitpos_x && y == game->exitpos_y)
			game->map[y][x + 1] = 'E';
		else
			game->map[y][x + 1] = '0';
	}
	else if (movement == 2)
	{
		x++;
		if (game->map[y][x] == '1' || !(right_move(game, x, y)))
			return (0);
		if (x - 1 == game->exitpos_x && y == game->exitpos_y)
			game->map[y][x - 1] = 'E';
		else
			game->map[y][x - 1] = '0';
	}
	ft_printf("Count movement : %i\n", game->counter);
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	if (command == 53)
		exit_point(game, "", 1);
	if (command == 13)
		works = keyboard_w_s(game, command, 0, 0);
	if (command == 1)
		works = keyboard_w_s(game, command, 0, 0);
	if (command == 0)
		works = keyboard_a_d(game, command, 0, 0);
	if (command == 2)
		works = keyboard_a_d(game, command, 0, 0);
	if (works)
		adding_in_graphics(game);
	return (1);
}
