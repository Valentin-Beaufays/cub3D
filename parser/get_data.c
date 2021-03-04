#include "../includes/cub3d.h"

void get_resolution(t_temp *temp, t_cub3d *data)
{
    if (temp->x < MIN_RES || temp->x > MAX_RES)
        free_data_err("invalid horizontal resolution", temp, data, 0);
    if (temp->y < MIN_RES || temp->y > MAX_RES)
        free_data_err("invalid vertical resolution", temp, data, 0);
    data->def[0] = temp->x;
    data->def[1] = temp->y;
    printf("resolution: %i x %i\n", data->def[0], data->def[1]);
}

void get_textures(t_temp *temp, t_cub3d *data)
{

}

void get_fc(t_temp *temp, t_cub3d *data)
{
    size_t i;
    int floor;
    int ceiling;

    i = 0;
    floor = 0;
    ceiling = 0;
    while (i < 3)
    {
        if (temp->ceiling[i] < 0 || temp->ceiling[i] > 255)
            free_data_err("invalid RGB values for ceiling", temp, data, 1);
        if (temp->floor[i] < 0 || temp->floor[i] > 255)
            free_data_err("invalid RGB values for floor", temp, data, 1);
        i++;
    }
    i = 0;
    while (i < 3)
    {
        data->color_floor += (pow(256, (2 - i) * temp->floor[i]));
        data->color_ceil += (pow(256, (2 - i) * temp->ceiling[i]));
        i++;
    }
    printf("f_color: %i\nc_color: %i\n", data->color_floor, data->color_ceil);
}

t_cub3d *get_data(t_temp *temp)
{
    t_cub3d *data;

    if (!(data = malloc(sizeof(*data))))
        free_tmp_err(strerror(errno), temp, 0);
    get_resolution(temp, data);
    get_texture(temp, data);
    get_fc(temp, data);
    //get_map(temp, data);
    //free_temp(temp);
    return (data);
}