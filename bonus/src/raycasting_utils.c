# include "../cub3d_bonus.h"

void	clear_screen(t_data *data, int color)
{
	int	x;
	int	y;
	int	pixel;

	x = 0;
	y = 0;
	while (y < data->img.height)
	{
		x = 0;
		while (x < data->img.width)
		{
			pixel = y * data->img.size_line + x * (data->img.bpp / 8);
			data->img.data[pixel] = color & 0xFF;
			data->img.data[pixel + 1] = (color >> 8) & 0xFF;
			data->img.data[pixel + 2] = (color >> 16) & 0xFF;
			x++;
		}
		y++;
	}
}

void	calculate_step_and_side_dist(t_ray *ray, t_data *data)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.y) * ray->delta_dist_y;
	}
}

void	perform_dda(t_ray *ray, t_map *map, t_player *player)
{
	int	map_x;
	int	map_y;

	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		map_x = ray->map_x / CELL_SIZE;
		map_y = ray->map_y / CELL_SIZE;

		if (map->grid[map_y][map_x] == 'D')
		{
			ray->is_door = 1;
			if (abs(map_x - (int)(player->x / CELL_SIZE)) <= 1
				&& abs(map_y - (int)(player->y / CELL_SIZE)) <= 1)
			{
				ray->hit = 0;
			}
			else
			{
				ray->hit = 2;
			}
		}
		else if (map->grid[map_y][map_x] == '1')
		{
			ray->hit = 1;
		}
	}
}