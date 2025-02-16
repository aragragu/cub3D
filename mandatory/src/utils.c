/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:01 by aragragu          #+#    #+#             */
/*   Updated: 2025/02/16 17:21:35 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	quit(char *msg)
{
	perror(msg);
	ft_malloc(1, FREE);
	exit(EXIT_FAILURE);
}

int	game_loop(t_data *data)
{
	render(data);
	move_player(data);
	return (0);
}
