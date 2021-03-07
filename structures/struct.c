#include "../includes/cub3d.h"

void	init_temp(t_temp *temp, int fd)
{
	temp->fd = fd;
	temp->line = NULL;
	temp->trim = NULL;
	temp->x = 0;
	temp->y = 0;
	temp->north = NULL;
	temp->south = NULL;
	temp->west = NULL;
	temp->east = NULL;
	temp->sprite = NULL;
	temp->floor[0] = -1;
	temp->floor[1] = -1;
	temp->floor[2] = -1;
	temp->ceiling[0] = -1;
	temp->ceiling[1] = -1;
	temp->ceiling[2] = -1;
	temp->map = NULL;
}

void	init_cub3d(t_cub3d *data)
{
	data->x = 0;
	data->y = 0;
	data->rotation = 0;
	data->map = NULL;
	data->text_sprite = NULL;
	data->text_n = NULL;
	data->text_s = NULL;
	data->text_e = NULL;
	data->text_w = NULL;
	data->color_ceil = 0;
	data->color_floor = 0;
	data->def[0] = 0;
	data->def[1] = 0;
}
