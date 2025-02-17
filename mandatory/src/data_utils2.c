/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:30:18 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/17 18:30:47 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_plane(t_player *player)
{
	if (player->dir_y == -1)
	{
		player->plane_x = FOV;
		player->plane_y = 0;
	}
	else if (player->dir_y == 1)
	{
		player->plane_x = -FOV;
		player->plane_y = 0;
	}
	else if (player->dir_x == -1)
	{
		player->plane_x = 0;
		player->plane_y = -FOV;
	}
	else if (player->dir_x == 1)
	{
		player->plane_x = 0;
		player->plane_y = FOV;
	}
}

void	set_direction(t_player *player, double dir_x, double dir_y)
{
	player->dir_x = dir_x;
	player->dir_y = dir_y;
}
