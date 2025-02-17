/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:35:44 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/17 18:53:38 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	color_cell_matching(char cell)
{
	if (cell == '1')
		return (0xFFFFFF);
	if (cell == '0')
		return (0x000000);
	if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
		return (0xFF0000);
	if (cell == 'D')
		return (0x8B4513);
	return (0x0000FF);
}

void	draw_horizontal_line(t_img *img, int *x, int *y, int *p, int dx, int dy, int x2, int y2, int color)
{
	while (*x <= x2)
	{
		draw_pixel(img, *x, *y, color);
		if (*p > 0)
		{
			if (y2 > *y)
				*y += 1;
			else
				*y -= 1;
			*p -= 2 * dx;
		}
		*p += 2 * dy;
		(*x)++;
	}
}

void	draw_vertical_line(t_img *img, int *x, int *y, int *p, int dx, int dy, int x2, int y2, int color)
{
	while (*y <= y2)
	{
		draw_pixel(img, *x, *y, color);
		if (*p > 0)
		{
			if (x2 > *x)
				*x += 1;
			else
				*x -= 1;
			*p -= 2 * dy;
		}
		*p += 2 * dx;
		(*y)++;
	}
}

void	draw_line(t_img *img, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	calculate_line_steps(x1, y1, x2, y2, &dx, &dy, &p);
	x = x1;
	y = y1;
	if (dx > dy)
		draw_horizontal_line(img, &x, &y, &p, dx, dy, x2, y2, color);
	else
		draw_vertical_line(img, &x, &y, &p, dx, dy, x2, y2, color);
}

void draw_rectangle(t_img *img)
{
    int i;
    int j;

    i = 0;
    while (i < img->rect.height)
    {
        j = 0;
        while (j < img->rect.width)
        {
            put_pixel_to_image(img, img->rect.x + j, img->rect.y + i, img->rect.color);
            j++;
        }
        i++;
    }
}

// void	draw_rectangle(t_img *img, int x, int y, int width, int height, int color, int img_width, int img_height)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (j < width)
// 		{
// 			put_pixel_to_image(img, x + j, y + i, color, img_width, img_height);
// 			j++;
// 		}
// 		i++;
// 	}
// }
