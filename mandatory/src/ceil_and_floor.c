/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_and_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:42:25 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/17 17:44:43 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_viewport(t_data *data)
{
	int	player_x;
	int	player_y;

	player_x = (int)(data->player.x / CELL_SIZE);
	player_y = (int)(data->player.y / CELL_SIZE);
	data->viewport.start_x = player_x - (MINIMAP_WIDTH
			/ (2 * (CELL_SIZE / MINIMAP_SCALE)));
	data->viewport.start_y = player_y - (MINIMAP_HEIGHT
			/ (2 * (CELL_SIZE / MINIMAP_SCALE)));
	data->viewport.end_x = player_x + (MINIMAP_WIDTH
			/ (2 * (CELL_SIZE / MINIMAP_SCALE)));
	data->viewport.end_y = player_y + (MINIMAP_HEIGHT
			/ (2 * (CELL_SIZE / MINIMAP_SCALE)));
}

void	ceil_and_floor_filling(t_data *data, int x, int y)
{
	while (x < data->img.width)
	{
		data->viewport.floor_x += data->viewport.floor_step_x;
		data->viewport.floor_y += data->viewport.floor_step_y;
		if (y < data->img.height / 2)
			draw_pixel(&data->img, x, y, data->game.c_ceiling);
		else
			draw_pixel(&data->img, x, y, data->game.c_floor);
		x++;
	}
}

void	render_ceiling_and_floor(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->img.height)
	{
		x = 0;
		ceil_and_floor_filling(data, x, y);
		y++;
	}
}
