/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:39:06 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/18 15:18:30 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	player_dir(t_data *data, int player_x, int player_y)
{
	int		i;
	int		steps;
	double	dx;
	double	dy;

	i = 1;
	steps = 10;
	dx = ((int)(data->player.dir_x * CELL_SIZE / 2)) / (double)steps;
	dy = ((int)(data->player.dir_y * CELL_SIZE / 2)) / (double)steps;
	data->img.width = MAP_WIDTH;
	data->img.height = MAP_HEIGHT;
	data->rect.width = 2;
	data->rect.height = 2;
	while (i <= steps)
	{
		data->rect.x = player_x + (int)(dx * i) - 1;
		data->rect.y = player_y + (int)(dy * i) - 1;
		draw_rectangle(&data->img, data->rect,
			0x00FF00 - (0x000FFF * i));
		i++;
	}
}

void	draw_player_on_minimap(t_data *data)
{
	int	player_x;
	int	player_y;

	player_x = (MINIMAP_WIDTH / 2) - 2;
	player_y = (MINIMAP_HEIGHT / 2) - 2;
	data->img.width = MINIMAP_WIDTH;
	data->img.height = MINIMAP_HEIGHT;
	data->rect.x = player_x + 10;
	data->rect.y = player_y + 10;
	data->rect.width = 4;
	data->rect.height = 4;
	draw_rectangle(&data->img, data->rect, 0xFF00FF);
	player_dir(data, player_x + 12, player_y + 12);
}
