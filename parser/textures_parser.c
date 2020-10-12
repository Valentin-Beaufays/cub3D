#include "../includes/cub3d.h"

void    parse_no_texture(t_temp *temp)
{
    char    *line;

    line = temp->trim + 2;
    if (!(*line == ' '))
        free_temp_error("invalid NO line", temp);
    while(*line == ' ')
        line++;
    if(!check_path(line, ".xpm"))
        free_temp_error("NO texture file must be an xpm file", temp);
    temp->north = ft_strdup(line);
}

void    parse_so_texture(t_temp *temp)
{
    char    *line;

    line = temp->trim + 2;
    if (!(*line == ' '))
        free_temp_error("invalid SO line", temp);
    while(*line == ' ')
        line++;
    if(!check_path(line, ".xpm"))
        free_temp_error("SO texture file must be an xpm file", temp);
    temp->south = ft_strdup(line);
}

void    parse_we_texture(t_temp *temp)
{
    char    *line;

    line = temp->trim + 2;
    if (!(*line == ' '))
        free_temp_error("invalid WE line", temp);
    while(*line == ' ')
        line++;
    if(!check_path(line, ".xpm"))
        free_temp_error("WE texture file must be an xpm file", temp);
    temp->west = ft_strdup(line);
}

void    parse_ea_texture(t_temp *temp)
{
    char    *line;

    line = temp->trim + 2;
    if (!(*line == ' '))
        free_temp_error("invalid EA line", temp);
    while(*line == ' ')
        line++;
    if(!check_path(line, ".xpm"))
        free_temp_error("EA texture file must be an xpm file", temp);
    temp->east = ft_strdup(line);
}

void    parse_s_texture(t_temp *temp)
{
    char    *line;

    line = temp->trim + 2;
    if (!(*line == ' '))
        free_temp_error("invalid S line", temp);
    while(*line == ' ')
        line++;
    if(!check_path(line, ".xpm"))
        free_temp_error("S texture file must be an xpm file", temp);
    temp->sprite = ft_strdup(line);
}