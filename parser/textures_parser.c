#include "../includes/cub3d.h"

void    parse_no_texture(t_temp *temp)
{
    char    *line;

    line = temp->trim + 2;
    if (!(*line == ' '))
        free_tmp_err("invalid NO line", temp, 3);
    while(*line == ' ')
        line++;
    if(!check_path(line, ".xpm"))
        free_tmp_err("NO texture file must be an xpm file", temp, 3);
    temp->north = ft_strdup(line);
}

void    parse_so_texture(t_temp *temp)
{
    char    *line;

    line = temp->trim + 2;
    if (!(*line == ' '))
        free_tmp_err("invalid SO line", temp, 3);
    while(*line == ' ')
        line++;
    if(!check_path(line, ".xpm"))
        free_tmp_err("SO texture file must be an xpm file", temp, 3);
    temp->south = ft_strdup(line);
}

void    parse_we_texture(t_temp *temp)
{
    char    *line;

    line = temp->trim + 2;
    if (!(*line == ' '))
        free_tmp_err("invalid WE line", temp, 3);
    while(*line == ' ')
        line++;
    if(!check_path(line, ".xpm"))
        free_tmp_err("WE texture file must be an xpm file", temp, 3);
    temp->west = ft_strdup(line);
}

void    parse_ea_texture(t_temp *temp)
{
    char    *line;

    line = temp->trim + 2;
    if (!(*line == ' '))
        free_tmp_err("invalid EA line", temp, 3);
    while(*line == ' ')
        line++;
    if(!check_path(line, ".xpm"))
        free_tmp_err("EA texture file must be an xpm file", temp, 3);
    temp->east = ft_strdup(line);
}

void    parse_s_texture(t_temp *temp)
{
    char    *line;

    line = temp->trim + 1;
    if (!(*line == ' '))
        free_tmp_err("invalid S line", temp, 3);
    while(*line == ' ')
        line++;
    if(!check_path(line, ".xpm"))
        free_tmp_err("S texture file must be an xpm file", temp, 3);
    temp->sprite = ft_strdup(line);
}