/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:57:24 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/17 17:57:55 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key, t_data *data)
{
	if (key == W_KEY)
		data->player.forward = 1;
	if (key == S_KEY)
		data->player.backward = 1;
	if (key == A_KEY)
		data->player.left = 1;
	if (key == D_KEY)
		data->player.right = 1;
	if (key == LEFT_KEY)
		data->player.rotate_left = 1;
	if (key == RIGHT_KEY)
		data->player.rotate_right = 1;
	if (key == ESCAPE_KEY)
		quit("Game exited successfully!");
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == W_KEY)
		data->player.forward = 0;
	if (key == S_KEY)
		data->player.backward = 0;
	if (key == A_KEY)
		data->player.left = 0;
	if (key == D_KEY)
		data->player.right = 0;
	if (key == LEFT_KEY)
		data->player.rotate_left = 0;
	if (key == RIGHT_KEY)
		data->player.rotate_right = 0;
	return (0);
}
