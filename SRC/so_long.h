/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:34:12 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/08 17:38:58 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include "../GNL/get_next_line.h"

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}	t_map;

typedef struct s_player
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	size;
	int	player;
	int	collectible;
	int	exit;
}	t_player;

typedef struct s_game
{
	void	*init;
	void	*window;
	void	*image;
	int		width;
	int		height;
	int		y;
	int		x;
	char	**map;
	int		coin;
}	t_game;

typedef struct s_image
{
	void	*wall;
	void	*player;
	void	*back_ground;
	void	*exit;
	void	*coin;
}	t_image;

void	add_back(t_map **head, t_map *node);
t_map	*creat_node(char	*line);
int		list_size(t_map *head);
void	ft_clean(t_map **head);

char	**check_map(char *name, t_map **head_map, t_game *game);
void	ft_puterror(char *str);
void	check_line(char **map, int size);
void	if_valid_map(char **map, int size, t_player *player);
void	*ft_memset(void *b, int c, size_t len);
char	**map_copy(char **map, int size);
void	ft_clean_map(char **map, int size);
void	check_map_if_valid(char	**map);
void	start_game(t_game *game, char **map);
int		handel_exit(t_game *game);
int		handel_key(int key, t_game *game);
void	find_player(char **map, t_game *game);

void	move_forward(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
#endif
