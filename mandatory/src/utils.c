# include "../cub3d.h"

void quit(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int game_loop(t_data *data)
{
    render(data);
    move_player(data);
    // usleep(16667); // 60fps
    return (0);
}