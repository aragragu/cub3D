#include "../cub3d.h"

void render(t_data *data)
{
    clear_img(data);
    render_ceiling_and_floor(data);
    raycast(data);
}


