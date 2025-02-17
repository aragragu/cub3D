/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:03:23 by tboussad          #+#    #+#             */
/*   Updated: 2025/02/17 18:35:08 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	handle_exit(void)
{
	printf("Exiting the program...\n");
	ft_malloc(0, FREE);
	exit(0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_hook(data->win, 17, 0, handle_exit, NULL);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2)
	{
		file_parsing(&data, argv[1]);
		data_init(&data);
		setup_mouse_rotation(&data);
		setup_hooks(&data);
		mlx_mouse_hook(data.win, mouse_press, &data);
		mlx_loop(data.mlx);
		free_textures(&data);
		ft_malloc(0, FREE);
	}
	else
		my_perror(1, "wrong arguments\n");
	return (0);
}
