/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:35:41 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/17 18:43:36 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	get_pixel_index(int x, int y, t_img *img)
{
	return (y * img->size_line + x * (img->bpp / 8));
}

void	draw_pixel(t_img *img, int x, int y, int color)
{
	int	pixel_index;

	pixel_index = get_pixel_index(x, y, img);
	*(unsigned int *)(img->data + pixel_index) = color;
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	unsigned char	*dst;

	if (x >= 0 && y >= 0 && x < img->img_width && y < img->img_height)
	{
		dst = img->data + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	clear_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->img.img_width = MAP_WIDTH;
	data->img.img_height = MAP_HEIGHT;
	while (i < MAP_WIDTH)
	{
		j = 0;
		while (j < MAP_HEIGHT)
		{
			put_pixel_to_image(&data->img, i, j, 0);
			j++;
		}
		i++;
	}
}

// void	calculate_line_steps(int x1, int y1, int x2, int y2, int *dx, int *dy, int *p)
// {
// 	*dx = abs(x2 - x1);
// 	*dy = abs(y2 - y1);
// 	*p = 2 * (*dy) - (*dx);
// }
