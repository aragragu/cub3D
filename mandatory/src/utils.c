/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:01 by aragragu          #+#    #+#             */
/*   Updated: 2025/02/17 15:17:57 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	quit(char *msg)
{
	my_perror(0, msg);
}

int	game_loop(t_data *data)
{
	render(data);
	move_player(data);
	return (0);
}
