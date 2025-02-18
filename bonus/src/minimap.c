/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:03:41 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/18 15:20:13 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_minimap_tile(t_data *data, int x, int y)
{
	int	tile_x;
	int	tile_y;

	tile_x = (x - data->minimap.start_x) * (CELL_SIZE / MINIMAP_SCALE);
	tile_y = (y - data->minimap.start_y) * (CELL_SIZE / MINIMAP_SCALE);
	data->img.width = MINIMAP_WIDTH;
	data->img.height = MINIMAP_HEIGHT;
	data->rect.x = tile_x + 10;
	data->rect.y = tile_y + 10;
	data->rect.width = (CELL_SIZE / MINIMAP_SCALE);
	data->rect.height = (CELL_SIZE / MINIMAP_SCALE);
	draw_rectangle(&data->img, data->rect,
		color_cell_matching(data->map.grid[y][x]));
}

void	draw_minimap_tiles(t_data *data)
{
	int	y;
	int	x;

	y = data->minimap.start_y;
	while (y <= data->minimap.end_y)
	{
		x = data->minimap.start_x;
		while (x <= data->minimap.end_x)
		{
			if (x >= 0 && y >= 0 && y < data->map.height
				&& data->map.grid[y] != NULL
				&& x < (int)ft_strlen(data->map.grid[y]))
				draw_minimap_tile(data, x, y);
			x++;
		}
		y++;
	}
}

void	draw_minimap_frame(t_data *data)
{
	int	frame_color;
	int	frame_thickness;

	frame_thickness = 5;
	frame_color = MINIMAP_FRAME_COLOR;
	data->rect.x = 10 - frame_thickness;
	data->rect.y = 10 - frame_thickness;
	data->rect.width = MINIMAP_WIDTH + (2 * frame_thickness);
	data->rect.height = MINIMAP_HEIGHT + (2 * frame_thickness);
	draw_rectangle(&data->img, data->rect,
		frame_color);
	data->rect.x = 10;
	data->rect.y = 10;
	data->rect.width = MINIMAP_WIDTH;
	data->rect.height = MINIMAP_HEIGHT;
	draw_rectangle(&data->img, data->rect, 0x000000);
}

void	render_minimap(t_data *data)
{
	calculate_viewport(data);
	draw_minimap_frame(data);
	draw_minimap_tiles(data);
	draw_player_on_minimap(data);
}
