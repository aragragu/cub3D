# include "../cub3d.h"

void init_player_defaults(t_player *player)
{
    player->forward = 0;
    player->backward = 0;
    player->left = 0;
    player->right = 0;
    player->rotate_left = 0;
    player->rotate_right = 0;
    player->move_speed = MOVE_SPEED;  //4
    player->rot_speed = ROT_SPEED;
    player->prev_x = MAP_WIDTH / 2;
    player->first_time = 1;
}

void player_init(t_map *map, t_player *player)
{
    if (!find_player_position(map, player))
        quit("error: Player not found in the map !");
    init_player_defaults(player);
    init_player_direction(player, map->grid[(int)player->y / CELL_SIZE][(int)player->x / CELL_SIZE]);
}

void init_img(t_data *data)
{
    data->img.width = MAP_WIDTH;
    data->img.height = MAP_HEIGHT;
    data->img.img_ptr = mlx_new_image(data->mlx, data->img.width, data->img.height);
    if (!data->img.img_ptr)
        quit("Error: Image creation failed!");
    data->img.data = (unsigned char *)mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.size_line, &data->img.endian);
    if (!data->img.data)
        quit("Error: Failed to get image data address!");
}

void init_player_trail(t_player_trail *trail)
{
    trail->size = 0;
}

void data_init(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        quit("Error: MiniLibX initialization failed!");
    if (data->map.grid == NULL)
        quit("Error: Map initialization failed!");
    data->win = mlx_new_window(data->mlx, MAP_WIDTH, MAP_HEIGHT, "Cub3D");
    if (!data->win)
        quit("Error: Window creation failed!");
    mlx_string_put(data->mlx, data->win, 1200, 400, 0xFFFFFF, "Loading textures...");
    images_init(data);
    colors_init(data);
    player_init(&data->map, &data->player);
    init_player_trail(&data->player_trail);
    init_img(data);
}
