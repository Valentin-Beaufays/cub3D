/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:08:01 by valentin          #+#    #+#             */
/*   Updated: 2020/09/23 15:42:28 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_error(char *error)
{
	printf("Error\n%s\n", error);
	exit(-1);
}

void	free_error(char *error, void *to_free)
{
	free(to_free);
	ft_error(error);
}

int check_path(char *path)
{
	size_t len;

	len = ft_strlen(path);
	if (ft_strcmp(path + (len - 4), ".cub"))
		return (0);
	return(1);
}

int	parse_resolution(char *line, t_param *data)
{
	line++;
	if (!ft_isspace(*line))
		//invalid
	while(ft_isspace(*line))
		line++;
	if (*line == '+' || *line == '-' || !(data->x = ft_atoi(line)))
		//invalid size
	while (ft_isdigit(*line))
		line++;
	if (!ft_isspace(*line))
		//invalid
	while(ft_isspace(*line))
		line++;
	if (*line == '+' || *line == '-' || !(data->y = ft_atoi(line)))
		//invalid size
	while (ft_isdigit(*line))
		line++;
	while(*line)
	{
		if (!(ft_isspace(*line)))
		{
			//invalid
		}
	}
	return(1);
}

int	get_info(char *line, t_param *data)
{
	int		ret;

	if (!ft_strncmp(line, "R", 1))
		ret = parse_resolution(line, data);
	else if (!ft_strncmp(line, "NO", 2))
		//NO
	else if (!ft_strncmp(line, "SO", 2))
		//SO
	else if (!ft_strncmp(line, "WE", 2))
		//WE
	else if (!ft_strncmp(line, "EA", 2))
		//EA
	else if (!ft_strncmp(line, "F", 1))
		//F
	else if (!ft_strncmp(line, "C", 1))
		//C
	else if(ft_strcmp(line, "\0"))
		ret = 0;
return (ret);
}

int	get_map(char *line, t_param *data)
{
	printf("%s\n", line);
	return (1);
}

int	parse_arg(int fd, t_param *data)
{
	char	*line;
	char	*trim;
	int		ret;

	while (!data->error && !ret && get_next_line(fd, &line))
	{
		if (!(trim = ft_strtrim(line, " ")))
			data->error = strerror(errno);
		else
		{
			ret = get_info(trim, data);
			free(trim);
		}
		if (!ret)
			data->prev_line = ft_strdup(line);
		free(line);
	}
	return (1);
}

int	cub_parser(char *path, t_param *data)
{
	int		fd;
	int		is_map;

	is_map = 0;
	if(!check_path(path))
		free_error("file must end with .cub", data);
	if ((fd = open(path, O_RDONLY)) == -1)
		free_error(strerror(errno), data);
	parse_arg(fd, data);
	close(fd);
	return (1);
}
