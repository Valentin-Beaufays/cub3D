#include "../includes/cub3d.h"

void	get_no_texture(t_temp *temp, t_cub3d *data)
{
	size_t	i;
	int		space;

	i = 0;
	space = 0;
	while (temp->north[i])
	{
		if (temp->north[i] == ' ')
			space = i;
		if (space > 0 && temp->north[i] != ' ')
			free_data_err("NO texture contains too many arguments", temp, data);
		i++;
	}
	if (!(data->text_n = ft_strtrim(temp->north, " ")))
		free_data_err(strerror(errno), temp, data);
	if (!check_path(data->text_n, ".xpm"))
		free_data_err("NO texture must be an xpm file", temp, data);
}

void	get_so_texture(t_temp *temp, t_cub3d *data)
{
	size_t	i;
	int		space;

	i = 0;
	space = 0;
	while (temp->south[i])
	{
		if (temp->south[i] == ' ')
			space = i;
		if (space > 0 && temp->south[i] != ' ')
			free_data_err("SO texture contains too many arguments", temp, data);
		i++;
	}
	if (!(data->text_s = ft_strtrim(temp->south, " ")))
		free_data_err(strerror(errno), temp, data);
	if (!check_path(data->text_s, ".xpm"))
		free_data_err("SO texture must be an xpm file", temp, data);
}

void	get_we_texture(t_temp *temp, t_cub3d *data)
{
	size_t	i;
	int		space;

	i = 0;
	space = 0;
	while (temp->west[i])
	{
		if (temp->west[i] == ' ')
			space = i;
		if (space > 0 && temp->west[i] != ' ')
			free_data_err("WE texture contains too many arguments", temp, data);
		i++;
	}
	if (!(data->text_w = ft_strtrim(temp->west, " ")))
		free_data_err(strerror(errno), temp, data);
	if (!check_path(data->text_w, ".xpm"))
		free_data_err("WE texture must be an xpm file", temp, data);
}

void	get_ea_texture(t_temp *temp, t_cub3d *data)
{
	size_t	i;
	int		space;

	i = 0;
	space = 0;
	while (temp->east[i])
	{
		if (temp->east[i] == ' ')
			space = i;
		if (space > 0 && temp->east[i] != ' ')
			free_data_err("EA texture contains too many arguments", temp, data);
		i++;
	}
	if (!(data->text_e = ft_strtrim(temp->east, " ")))
		free_data_err(strerror(errno), temp, data);
	if (!check_path(data->text_e, ".xpm"))
		free_data_err("EA texture must be an xpm file", temp, data);
}

void	get_s_texture(t_temp *temp, t_cub3d *data)
{
	size_t	i;
	int		space;

	i = 0;
	space = 0;
	while (temp->sprite[i])
	{
		if (temp->sprite[i] == ' ')
			space = i;
		if (space > 0 && temp->sprite[i] != ' ')
			free_data_err("S texture contains too many arguments", temp, data);
		i++;
	}
	if (!(data->text_sprite = ft_strtrim(temp->sprite, " ")))
		free_data_err(strerror(errno), temp, data);
	if (!check_path(data->text_sprite, ".xpm"))
		free_data_err("S texture must be an xpm file", temp, data);
}
