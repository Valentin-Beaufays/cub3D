#include "../includes/cub3d.h"

void check_missing_data(t_temp *temp)
{
    if (temp->x == 0 || temp->y == 0)
        free_tmp_err("resolution is missing", temp, 0);
    if (!temp->north || !temp->south || !temp->west || !temp->east || !temp->sprite)
        free_tmp_err("a texture is missing", temp, 0);
    if (temp->floor[0] == -1)
        free_tmp_err("floor is missing", temp, 0);
    if (temp->ceiling[0] == -1)
        free_tmp_err("ceiling is missing", temp, 0);
}

void get_resolution(t_temp *temp, t_cub3d *data)
{
    if (temp->x < MIN_RES || temp->x > MAX_RES)
        free_data_err("invalid horizontal resolution", temp, data);
    if (temp->y < MIN_RES || temp->y > MAX_RES)
        free_data_err("invalid vertical resolution", temp, data);
    data->def.x = temp->x;
    data->def.y = temp->y;
}

void get_textures(t_temp *temp, t_cub3d *data)
{
    get_no_texture(temp, data);
    get_so_texture(temp, data);
    get_we_texture(temp, data);
    get_ea_texture(temp, data);
    get_s_texture(temp, data);
}

void get_fc(t_temp *temp, t_cub3d *data)
{
    size_t i;

    i = 0;
    while (i < 3)
    {
        if (temp->ceiling[i] < 0 || temp->ceiling[i] > 255)
            free_data_err("invalid RGB values for ceiling", temp, data);
        if (temp->floor[i] < 0 || temp->floor[i] > 255)
            free_data_err("invalid RGB values for floor", temp, data);
        i++;
    }
        data->color_floor = rgb_to_int(temp->floor[0], temp->floor[1], temp->floor[2]);
        data->color_ceil = rgb_to_int(temp->ceiling[0], temp->ceiling[1], temp->ceiling[2]);
}

t_cub3d *get_data(t_temp *temp)
{
    t_cub3d *data;

    check_missing_data(temp);
    if (!(data = malloc(sizeof(*data))))
        free_tmp_err(strerror(errno), temp, 0);
	init_cub3d(data);
	get_resolution(temp, data);
    data->stepRad = round_rad(data->fov / data->def.x);
	get_textures(temp, data);
    get_fc(temp, data);
    get_map(temp, data);
    data->stepRad = data->fov / data->def.x;
    free_temp(temp);
    return (data);
}
