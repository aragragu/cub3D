/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:59:02 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/19 12:43:51 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_exit(void)
{
	printf("Exiting the program...\n");
	ft_malloc(0, FREE);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2)
	{
		file_parsing(&data, argv[1]);
		data_init(&data);
		mlx_hook(data.win, 2, 1L << 0, key_press, &data);
		mlx_hook(data.win, 3, 1L << 1, key_release, &data);
		mlx_loop_hook(data.mlx, game_loop, &data);
		mlx_hook(data.win, 17, 0, handle_exit, NULL);
		mlx_loop(data.mlx);
		free_textures(&data);
		ft_malloc(0, FREE);
	}
	else
		my_perror(1, "Error:\n wrong arguments\n");
	return (0);
}
