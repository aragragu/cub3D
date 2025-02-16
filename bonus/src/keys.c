/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:58:01 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/16 16:06:45 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d_bonus.h"

int	key_press(int key, t_data *data)
{
	handle_key_press(key, data);
	handle_key_press_rotation(key, data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	handle_key_release(key, data);
	handle_key_release_rotation(key, data);
	return (0);
}
