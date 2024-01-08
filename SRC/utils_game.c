/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:36:52 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/08 17:49:42 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
			{
				game->y = i;
				game->x = j;
			}
			if (map[i][j] == 'C')
				game->coin++;
			j++;
		}
		i++;
	}
}

int	handel_exit(t_game *game)
{
	(void) game;
	exit(0);
}

int	handel_key(int key, t_game *game)
{
	if (key == 53)
	{
		mlx_destroy_window(game->init, game->window);
		exit(0);
	}
	else if (key == 126)
		move_forward(game);
	else if (key == 125)
		move_down(game);
	else if (key == 123)
		move_left(game);
	else if (key == 124)
		move_right(game);
	return (0);
}
