/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:45:41 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/17 18:30:42 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_player_cell(char cell)
{
	return (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W');
}

void	player_direction_exception_error(char cell, t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 0;
	printf("error: Invalid player direction '%c'. Defaulting to (0, 0).\n",
		cell);
}

void	set_player_direction(char cell, t_player *player)
{
	if (cell == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (cell == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (cell == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (cell == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	else
		player_direction_exception_error(cell, player);
}

void	init_player_direction(t_player *player, char orientation)
{
	if (orientation == 'N')
		set_direction(player, 0, -1);
	else if (orientation == 'S')
		set_direction(player, 0, 1);
	else if (orientation == 'E')
		set_direction(player, 1, 0);
	else if (orientation == 'W')
		set_direction(player, -1, 0);
}

int	find_player_position(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (is_player_cell(map->grid[y][x]))
			{
				player->x = x;
				player->y = y;
				set_player_direction(map->grid[y][x], player);
				set_player_plane(player);
				map->grid[y][x] = '0';
				player->x = (player->x * CELL_SIZE) + (CELL_SIZE / 2);
				player->y = (player->y * CELL_SIZE) + (CELL_SIZE / 2);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
