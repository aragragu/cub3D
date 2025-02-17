/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:35:47 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/17 18:35:48 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	render(t_data *data)
{
	clear_img(data);
	render_ceiling_and_floor(data);
	raycast(data);
	render_minimap(data);
	render_gun_sprite(data);
}
