/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:01:35 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/08 17:15:56 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_forward(t_game *game)
{
	if (game->map[game->y - 1][game->x] == '1')
		return ;
	if (game->map[game->y - 1][game->x] == 'E' && game->coin != 0)
		return ;
	if (game->map[game->y - 1][game->x] == 'E' && game->coin == 0)
		exit(0);
	if (game->map[game->y - 1][game->x] == 'C')
		game->coin--;
	game->map[game->y][game->x] = '0';
	game->map[game->y - 1][game->x] = 'P';
	game->y = game->y - 1;
}

void	move_down(t_game *game)
{
	if (game->map[game->y + 1][game->x] == '1')
		return ;
	if (game->map[game->y + 1][game->x] == 'E' && game->coin != 0)
		return ;
	if (game->map[game->y + 1][game->x] == 'E' && game->coin == 0)
		exit(0);
	if (game->map[game->y + 1][game->x] == 'C')
		game->coin--;
	game->map[game->y][game->x] = '0';
	game->map[game->y + 1][game->x] = 'P';
	game->y = game->y + 1;
}

void	move_left(t_game *game)
{
	if (game->map[game->y][game->x - 1] == '1')
		return ;
	if (game->map[game->y][game->x - 1] == 'E' && game->coin != 0)
		return ;
	if (game->map[game->y][game->x - 1] == 'E' && game->coin == 0)
		exit(0);
	if (game->map[game->y][game->x - 1] == 'C')
		game->coin--;
	game->map[game->y][game->x - 1] = 'P';
	game->map[game->y][game->x] = '0';
	game->x = game->x - 1;
}

void	move_right(t_game *game)
{
	if (game->map[game->y][game->x + 1] == '1')
		return ;
	if (game->map[game->y][game->x + 1] == 'E' && game->coin != 0)
		return ;
	if (game->map[game->y][game->x + 1] == 'E' && game->coin == 0)
		exit(0);
	if (game->map[game->y][game->x + 1] == 'C')
		game->coin--;
	game->map[game->y][game->x + 1] = 'P';
	game->map[game->y][game->x] = '0';
	game->x = game->x + 1;
}
