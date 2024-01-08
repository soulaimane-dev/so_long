/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:41:00 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/08 17:05:38 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker(char *name, char *target)
{
	while (*target != '\0')
	{
		if (*target != *name)
			return (0);
		target++;
		name++;
	}
	if (*name == '\0' && *target == '\0')
		return (1);
	return (0);
}

void	check_map_name(char *name)
{
	char	*target;

	target = ".ber";
	while (*name)
	{
		if (*name == target[0])
		{
			if (checker(name, target))
				return ;
		}
		name++;
	}
	ft_puterror("Error in name map\n");
}

void	open_map(char	*name, t_map **head_map)
{
	int		fd;
	char	*str;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_puterror("Error in name map\n");
	str = get_next_line(fd);
	if (!str)
		(ft_puterror("Error in name map\n"), exit(EXIT_FAILURE));
	while (str)
	{
		add_back(head_map, creat_node(str));
		free(str);
		str = get_next_line(fd);
	}
	free(str);
}

char	**full_map(t_map **head, char **map)
{
	t_map	*curr;
	int		size;
	int		i;

	curr = *head;
	size = list_size(*head);
	map = malloc((size + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map[i] = ft_strdup(curr->line);
		curr = curr->next;
		i++;
	}
	map[i] = NULL;
	ft_clean(head);
	return (map);
}

char	**check_map(char *name, t_map **head_map, t_game *game)
{
	char	**map;
	int		size;

	map = NULL;
	check_map_name(name);
	open_map(name, head_map);
	size = list_size(*head_map);
	map = full_map(head_map, map);
	check_line(map, size);
	game->width = ft_strlen(map[0]) - 1;
	game->height = size;
	return (map);
}
