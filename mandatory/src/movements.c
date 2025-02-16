# include "../cub3d.h"

void move_forward(t_player *player, t_map *map)
{
    double new_x;
    double new_y;

    new_x = player->x + player->dir_x * player->move_speed;
    new_y = player->y + player->dir_y * player->move_speed;
    if (is_walkable(map, (new_x / CELL_SIZE), (player->y / CELL_SIZE)))
        player->x = new_x;
    if (is_walkable(map, (player->x / CELL_SIZE), (new_y / CELL_SIZE)))
        player->y = new_y;
}

void move_backward(t_player *player, t_map *map)
{
    double new_x;
    double new_y;

    new_x = player->x - player->dir_x * player->move_speed;
    new_y = player->y - player->dir_y * player->move_speed;
    if (is_walkable(map, (new_x / CELL_SIZE), (player->y / CELL_SIZE)))
        player->x = new_x;
    if (is_walkable(map, (player->x / CELL_SIZE), (new_y / CELL_SIZE)))
        player->y = new_y;
}

void strafe_left(t_player *player, t_map *map)
{
    double new_x;
    double new_y;

    new_x = player->x - player->plane_x * player->move_speed;
    new_y = player->y - player->plane_y * player->move_speed;
    if (is_walkable(map, (new_x / CELL_SIZE), (player->y / CELL_SIZE)))
        player->x = new_x;
    if (is_walkable(map, (player->x / CELL_SIZE), (new_y / CELL_SIZE)))
        player->y = new_y;
}

void strafe_right(t_player *player, t_map *map)
{
    double new_x;
    double new_y;

    new_x = player->x + player->plane_x * player->move_speed;
    new_y = player->y + player->plane_y * player->move_speed;
    if (is_walkable(map, (new_x / CELL_SIZE), (player->y / CELL_SIZE)))
        player->x = new_x;
    if (is_walkable(map, (player->x / CELL_SIZE), (new_y / CELL_SIZE)))
        player->y = new_y;
}

void move_player(t_data *data)
{
    t_player *player;
    t_map *map;

    player = &data->player;
    map = &data->map;

    if (player->forward)
        move_forward(player, map);
    if (player->backward)
        move_backward(player, map);
    if (player->left)
        strafe_left(player, map);
    if (player->right)
        strafe_right(player, map);
    if (player->rotate_left)
        rotate_left(player);
    if (player->rotate_right)
        rotate_right(player);
}
