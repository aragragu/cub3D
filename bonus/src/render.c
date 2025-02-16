# include "../cub3d_bonus.h"

void	render(t_data *data)
{
	clear_img(data);
	render_ceiling_and_floor(data);
	raycast(data);
	render_minimap(data);
	render_gun_sprite(data);
}
