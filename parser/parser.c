#include "../includes/cub3d.h"

void	parse_resolution(t_temp *temp)
{
	char	*line;

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

int		get_arg(t_temp *temp)
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
	else if (!ft_strncmp(temp->trim, "C", 1))
		parse_ceiling(temp);
	else if (!ft_strncmp(temp->trim, "1", 1) || !ft_strncmp(temp->trim, "0", 1))
		return (0);
	else
		free_tmp_err("invalid line found", temp, 3);
	return (1);
}

void	parse_args(t_temp *temp)
{
	int	is_map;
	int	ret;
:
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

t_cub3D *cub_parser(char *path)
{
	int		fd;
	t_temp	temp;
	t_cub3D	*data;

	if (!check_path(path, ".cub"))
		ft_error("file must end with .cub");
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error(strerror(errno));
	init_temp(&temp, fd);
	parse_args(&temp);
	data = get_data(&temp);
	return (data);
}
