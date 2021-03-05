#include "../includes/cub3d.h"

void init_temp(t_temp *temp, int fd)
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
    temp->floor[0] = 0;
    temp->floor[1] = 0;
    temp->floor[2] = 0;
    temp->ceiling[0] = 0;
    temp->ceiling[1] = 0;
    temp->ceiling[2] = 0;
    temp->map = NULL;
}

void init_cub3D(t_cub3D *data)
{
    data->x = 0;
	data->y = 0;
	data->rotation = 0;
	data->map = NULL;
	data->text_sprite = NULL;
	data->text_N  = NULL;
	data->text_S  = NULL;
	data->text_E = NULL;
	data->text_W = NULL;
	data->color_ceil = 0;
	data->color_floor = 0;
	data->def[0] = 0;
    data->def[1] = 0;
}