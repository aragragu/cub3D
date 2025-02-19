/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:01 by aragragu          #+#    #+#             */
/*   Updated: 2025/02/19 12:38:43 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	quit(char *msg)
{
	my_perror(1, msg);
}

int	game_loop(t_data *data)
{
	render(data);
	move_player(data);
	return (0);
}
