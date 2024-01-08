/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:01:33 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/08 17:19:13 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_valid_1(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != 'F' && map[i][j] != '\n')
				ft_puterror("invalid map\n");
			j++;
		}
		i++;
	}
}

void	flood_fill_1(char **map, int x, int y, t_player *temp)
{
	temp->i = temp->size;
	temp->j = ft_strlen(map[0]);
	if (x < 0 || x >= temp->i || y < 0 || y >= temp->j || map[x][y]
		== 'F' || map[x][y] == '\n' || map[x][y] == '1')
	{
		return ;
	}
	else
	{
		map[x][y] = 'F';
		flood_fill_1(map, x + 1, y, temp);
		flood_fill_1(map, x - 1, y, temp);
		flood_fill_1(map, x, y + 1, temp);
		flood_fill_1(map, x, y - 1, temp);
	}
}

void	check_if_valid_2(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j]
				!= 'F' && map[i][j] != '\n' && map[i][j] != 'E')
				ft_puterror("invalid map\n");
			j++;
		}
		i++;
	}
}

void	flood_fill_2(char **map, int x, int y, t_player *temp)
{
	temp->i = temp->size;
	temp->j = ft_strlen(map[0]);
	if (x < 0 || x >= temp->i || y < 0 || y >= temp->j || map[x][y]
		== 'F' || map[x][y] == '\n' || map[x][y] == '1' || map[x][y] == 'E')
	{
		return ;
	}
	else
	{
		map[x][y] = 'F';
		flood_fill_2(map, x + 1, y, temp);
		flood_fill_2(map, x - 1, y, temp);
		flood_fill_2(map, x, y + 1, temp);
		flood_fill_2(map, x, y - 1, temp);
	}
}

void	if_valid_map(char **map, int size, t_player *player)
{
	char	**new_map1;
	char	**new_map2;

	player->size = size;
	new_map1 = map_copy(map, size);
	flood_fill_1(new_map1, player->x, player->y, player);
	check_if_valid_1(new_map1);
	new_map2 = map_copy(map, size);
	flood_fill_2(new_map2, player->x, player->y, player);
	check_if_valid_2(new_map2);
	ft_clean_map(new_map1, size);
	ft_clean_map(new_map2, size);
}
