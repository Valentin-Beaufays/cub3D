#include "../includes/cub3d.h"

int check_path(char *path, char *ext)
{
	size_t len;

	len = ft_strlen(path);
	if (ft_strcmp(path + (len - 4), ext))
		return (0);
    return (1);
}

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
    temp->floor_R = 0;
    temp->floor_G = 0;
    temp->floor_B = 0;
    temp->ceiling_R = 0;
    temp->ceiling_G = 0;
    temp->ceiling_B = 0;
    temp->map = NULL;
}

void	parse_resolution(t_temp *temp)
{
    char *line;

    line = temp->trim + 1;
	if (!(*line == ' '))
		free_tmp_err("invalid resolution line", temp, 3);
	while(*line == ' ')
		line++;
	if (*line == '+' || *line == '-' || !(temp->x = ft_atoi(line)))
		free_tmp_err("invalid resolution line", temp, 3);
	while (ft_isdigit(*line))
		line++;
	if (!(*line == ' '))
        free_tmp_err("invalid R line", temp, 3);
	while(*line == ' ')
		line++;
	if (*line == '+' || *line == '-' || !(temp->y = ft_atoi(line)))
		free_tmp_err("invalid R line", temp, 3);
	while (ft_isdigit(*line))
		line++;
	while(*line)
	{
		if (!(*line == ' '))
			free_tmp_err("invalid R line", temp, 3);
        line++;
	}
}

void parse_floor(t_temp *temp)
{
    char *line;

    line = temp->trim + 1;
    if (!(*line == ' '))
        free_tmp_err("invalid floor line", temp, 3);
    while (*line == ' ')
        line++;
    temp->floor_R = ft_atoi(line);
    if (*line == '+' || *line == '-' || temp->floor_R < 0 || temp->floor_R > 255)
		free_tmp_err("invalid floor line", temp, 3);
    while (ft_isdigit(*line))
        line++;
    while (*line == ' ')
        line++;
    if (*line != ',')
        free_tmp_err("missing \',\' in floor line", temp, 3);
    line++;
    while (*line == ' ')
        line++;
    temp->floor_G = ft_atoi(line);
    if (*line == '+' || *line == '-' || temp->floor_G < 0 || temp->floor_G > 255)
		free_tmp_err("invalid floor line", temp, 3);
    while (ft_isdigit(*line))
        line++;
    while (*line == ' ')
        line++;
    if (*line != ',')
        free_tmp_err("missing \',\' in floor line", temp, 3);
    line++;
    while (*line == ' ')
        line++;
    temp->floor_B = ft_atoi(line);
    if (*line == '+' || *line == '-' || temp->floor_B < 0 || temp->floor_B > 255)
		free_tmp_err("invalid floor line", temp, 3);
    while (ft_isdigit(*line))
        line++;
    while (*line)
    {
        if (*line != ' ')
            free_tmp_err("invalid floor line", temp, 3);
        line++;
    }
}

int	get_arg(t_temp *temp)
{
	if (!ft_strncmp(temp->trim, "R", 1))
		parse_resolution(temp);
	else if (!ft_strncmp(temp->trim, "NO", 2))
		parse_no_texture(temp);
	else if (!ft_strncmp(temp->trim, "SO", 2))
		parse_so_texture(temp);
	else if (!ft_strncmp(temp->trim, "WE", 2))
		parse_we_texture(temp);
	else if (!ft_strncmp(temp->trim, "EA", 2))
		parse_ea_texture(temp);
    else if (!ft_strncmp(temp->trim, "S", 1))
        parse_s_texture(temp);
	else if (!ft_strncmp(temp->trim, "F", 1))
		parse_floor(temp);
	/*else if (!ft_strncmp(line, "C", 1))
		//C*/
	else if (!ft_strncmp(temp->trim, "1", 1))
		return (0);
    else
        free_tmp_err("invalid line found", temp, 3);
return (1);
}

void    parse_map(t_temp *temp)
{
    //TO-DO
}

void    parse_args(t_temp *temp)
{
    int     is_map;
    int     ret;

    is_map = 0;
    while(!is_map && (ret = get_next_line(temp->fd, &(temp->line))))
    {
        if (ret == -1 )
            free_tmp_err(strerror(errno), temp, 0);
        if ((temp->trim = ft_strtrim(temp->line, " ")) == 0)
            free_tmp_err(strerror(errno), temp, 1);
        if(*(temp->trim) != 0)
        {
            if(!get_arg(temp))
                is_map = 1;
        }
        if (!is_map)
            free(temp->line);
        free(temp->trim);
    }
    if (!is_map)
        free_tmp_err("no map has been found", temp, 0);
    parse_map(temp);
}

t_data *cub_parser(char *path)
{
    int fd;
    t_temp temp;

    if (!check_path(path, ".cub"))
       ft_error("file must end with .cub");
	if ((fd = open(path, O_RDONLY)) == -1)
        ft_error(strerror(errno));
    init_temp(&temp, fd);
    parse_args(&temp);
    return (NULL);
}