/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_Map_Char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:24:12 by marvin            #+#    #+#             */
/*   Updated: 2024/09/05 11:24:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int parsing_map_char(t_map *map)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		while (j < map->x)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'P' && map->map[i][j] != 'E' && map->map[i][j] != 'C')
				error_message(INVALID_MAP_CHAR);
			j++;
		}
		j = 0;
		i++;
	}
	return (VALID_MAP_CHAR);
}

int parsing_map_char_player(t_map *map)
{
	unsigned int i;
	unsigned int j;
	unsigned int player;

	i = 0;
	j = 0;
	player = 0;
	while (i < map->y)
	{
		while (j < map->x)
		{
			if (map->map[i][j] == 'P')
				player++;
			j++;
		}
		j = 0;
		i++;
	}
	if (player != 1)
		error_message(INVALID_MAP_PLAYER);
	return (VALID_MAP_PLAYER);
}

int parsing_map_char_exit(t_map *map)
{
	unsigned int i;
	unsigned int j;
	unsigned int exit;

	i = 0;
	j = 0;
	exit = 0;
	while (i < map->y)
	{
		while (j < map->x)
		{
			if (map->map[i][j] == 'E')
				exit++;
			j++;
		}
		j = 0;
		i++;
	}
	if (exit != 1)
		error_message(INVALID_MAP_EXIT);
	return (VALID_MAP_EXIT);
}
