#include "../includes/cub3d.h"

int check_path(char *path, char *ext)
{
	size_t len;
    size_t ext_len;

	len = ft_strlen(path);
    ext_len = ft_strlen(ext);
    if (ext_len < len)
    {
	    if (ft_strcmp(path + (len - ext_len), ext))
		    return (0);
    }
    return (1);
}

void get_no_texture(t_temp *temp, t_cub3D *data)
{
    size_t  i;
    int space;

    i = 0;
    space = 0;
    while (temp->north[i])
    {
        if (temp->north[i] == ' ')
            space = i;
        if (space == 1 && temp->north[i] != ' ')
            free_data_err("NO texture contains too many arguments", temp, data, 0);
        i++;
    }
    if (!(data->text_N = ft_strtrim(temp->north, " ")))
        free_data_err(strerror(errno), temp, data, 0);
    if (check_path(data->text_N, ".xpm"))
        free_data_err("NO texture must be an xpm file", temp, data, 1);
}

void get_so_texture(t_temp *temp, t_cub3D *data)
{
    size_t  i;
    int space;

    i = 0;
    space = 0;
    while (temp->south[i])
    {
        if (temp->south[i] == ' ')
            space = i;
        if (space == 1 && temp->south[i] != ' ')
            free_data_err("SO texture contains too many arguments", temp, data, 0);
        i++;
    }
    if (!(data->text_S = ft_strtrim(temp->south, " ")))
        free_data_err(strerror(errno), temp, data, 0);
    if (check_path(data->text_S, ".xpm"))
        free_data_err("SO texture must be an xpm file", temp, data, 1);
}

void get_we_texture(t_temp *temp, t_cub3D *data)
{
    size_t  i;
    int space;

    i = 0;
    space = 0;
    while (temp->west[i])
    {
        if (temp->west[i] == ' ')
            space = i;
        if (space == 1 && temp->west[i] != ' ')
            free_data_err("WE texture contains too many arguments", temp, data, 0);
        i++;
    }
    if (!(data->text_W = ft_strtrim(temp->west, " ")))
        free_data_err(strerror(errno), temp, data, 0);
    if (check_path(data->text_W, ".xpm"))
        free_data_err("WE texture must be an xpm file", temp, data, 1);
}

void get_ea_texture(t_temp *temp, t_cub3D *data)
{
    size_t  i;
    int space;

    i = 0;
    space = 0;
    while (temp->east[i])
    {
        if (temp->east[i] == ' ')
            space = i;
        if (space == 1 && temp->east[i] != ' ')
            free_data_err("EA texture contains too many arguments", temp, data, 0);
        i++;
    }
    if (!(data->text_E = ft_strtrim(temp->east, " ")))
        free_data_err(strerror(errno), temp, data, 0);
    if (check_path(data->text_E, ".xpm"))
        free_data_err("EA texture must be an xpm file", temp, data, 1);
}

void get_s_texture(t_temp *temp, t_cub3D *data)
{
    size_t  i;
    int space;

    i = 0;
    space = 0;
    while (temp->sprite[i])
    {
        if (temp->sprite[i] == ' ')
            space = i;
        if (space == 1 && temp->sprite[i] != ' ')
            free_data_err("S texture contains too many arguments", temp, data, 0);
        i++;
    }
    if (!(data->text_sprite = ft_strtrim(temp->sprite, " ")))
        free_data_err(strerror(errno), temp, data, 0);
    if (check_path(data->text_sprite, ".xpm"))
        free_data_err("S texture must be an xpm file", temp, data, 1);
}