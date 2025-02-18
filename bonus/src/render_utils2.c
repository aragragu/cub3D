/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:19:41 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/18 15:30:52 by tboussad         ###   ########.fr       */
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

void	draw_rectangle(t_img *img, t_rect rect, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < rect.height)
	{
		j = 0;
		while (j < rect.width)
		{
			put_pixel_to_image(img, rect.x + j, rect.y + i, color);
			j++;
		}
		i++;
	}
}
