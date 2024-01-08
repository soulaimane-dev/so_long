/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:49:15 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/08 17:18:21 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_first_and_last(char **map, int size)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			ft_puterror("Error in map\n");
		i++;
	}
	i = 0;
	while (map[size - 1][i] && map[size - 1][i] != '\n')
	{
		if (map[size - 1][i] != '1')
			ft_puterror("Error in map\n");
		i++;
	}
	if (size == ft_strlen(map[0]) - 1)
	{
		ft_puterror("Error in map\n");
	}
}

void	check_beginning_and_end(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 2] != '1')
			ft_puterror("Error in map\n");
		i++;
	}
}

void	counter_map(char **map, t_player	*p)
{
	check_map_if_valid(map);
	while (map[p->i])
	{
		p->j = 0;
		while (map[p->i][p->j])
		{
			if (map[p->i][p->j] == 'C')
				p->collectible++;
			else if (map[p->i][p->j] == 'E')
				p->exit++;
			else if (map[p->i][p->j] == 'P')
			{
				p->x = p->i;
				p->y = p->j;
				p->player++;
			}
			p->j++;
		}
		p->i++;
	}
	if (p->collectible < 1 || p->exit != 1 || p->player != 1)
		ft_puterror("invalid map\n");
}

void	check_line(char **map, int size)
{
	int			i;
	int			len;
	t_player	player;

	ft_memset(&player, 0, sizeof(player));
	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			ft_puterror("Error in map\n");
		i++;
	}
	check_first_and_last(map, size);
	check_beginning_and_end(map);
	counter_map(map, &player);
	if_valid_map(map, size, &player);
}

char	**map_copy(char **map, int size)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc((size + 1) * sizeof(char *));
	if (new_map == NULL)
		return (NULL);
	while (i < size)
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
