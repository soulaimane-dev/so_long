/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:08:16 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/08 18:30:19 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	temp_full_map_image(t_game *game, t_player *player, t_image *image)
{
	if (game->map[player->i][player->j] == '1')
		mlx_put_image_to_window(game->init, game->window, image->wall \
		, player->x, player->y);
	else if (game->map[player->i][player->j] == '0')
		mlx_put_image_to_window(game->init, game->window, image->back_ground \
		, player->x, player->y);
	else if (game->map[player->i][player->j] == 'P')
	{
		mlx_put_image_to_window(game->init, game->window, image->back_ground \
		, player->x, player->y);
		mlx_put_image_to_window(game->init, game->window, image->player \
		, player->x, player->y);
	}
	else if (game->map[player->i][player->j] == 'C')
	{
		mlx_put_image_to_window(game->init, game->window, image->back_ground \
		, player->x, player->y);
		mlx_put_image_to_window(game->init, game->window, image->coin \
		, player->x, player->y);
	}
	else if (game->map[player->i][player->j] == 'E')
		mlx_put_image_to_window(game->init, game->window, image->exit \
		, player->x, player->y);
}

void	temp_full_image(t_game *game, t_image *image)
{
	int	height;
	int	width;

	height = 60;
	width = 60;
	image->back_ground = mlx_xpm_file_to_image(game->init, \
							"./textures/back_ground.xpm", &height, &width);
	if (!image->back_ground)
		ft_puterror("Error in image\n");
	image->coin = mlx_xpm_file_to_image(game->init, \
			"./textures/coin.xpm", &height, &width);
	if (!image->coin)
		ft_puterror("Error in image\n");
	image->player = mlx_xpm_file_to_image(game->init, \
		"./textures/player.xpm", &height, &width);
	if (!image->player)
		ft_puterror("Error in image\n");
	image->exit = mlx_xpm_file_to_image(game->init, \
		"./textures/exit.xpm", &height, &width);
	if (!image->exit)
		ft_puterror("Error in image\n");
	image->wall = mlx_xpm_file_to_image(game->init, \
		"./textures/wall.xpm", &height, &width);
	if (!image->wall)
		ft_puterror("Error in image\n");
}

int	full_map_image(t_game *game)
{
	t_image		image;
	t_player	player;

	temp_full_image(game, &image);
	player.y = 0;
	player.i = 0;
	while (game->map[player.i])
	{
		player.j = 0;
		player.x = 0;
		while (game->map[player.i][player.j])
		{
			temp_full_map_image(game, &player, &image);
			player.j++;
			player.x += 60;
		}
		player.i++;
		player.y += 60;
	}
	return (0);
}

void	start_game(t_game *game, char **map)
{
	game->init = mlx_init();
	if (!game->init)
		ft_puterror("Error in init\n");
	game->window = mlx_new_window(game->init, game->width * 60, \
					game->height * 60, "so_long");
	if (!game->window)
		ft_puterror("Error in window\n");
	game->map = map;
	game->coin = 0;
	find_player(game->map, game);
	mlx_hook(game->window, 17, 0, handel_exit, game);
	mlx_loop_hook(game->init, full_map_image, game);
	mlx_hook(game->window, 2, 0, handel_key, game);
	mlx_loop(game->init);
}
