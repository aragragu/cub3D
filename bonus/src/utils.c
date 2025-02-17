/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:52:59 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/17 14:47:49 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void quit(char *msg)
{
    my_perror(0, msg);
}

int	game_loop(t_data *data)
{
	render(data);
	move_player(data);
	return (0);
}
