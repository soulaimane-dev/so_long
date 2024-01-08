/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:33:09 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/08 17:03:33 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*head_map;
	t_game	game;
	char	**map;

	map = NULL;
	head_map = NULL;
	if (ac != 2)
		exit(1);
	map = check_map(av[1], &head_map, &game);
	start_game(&game, map);
}
