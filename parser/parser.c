/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:08:01 by valentin          #+#    #+#             */
/*   Updated: 2020/09/24 15:59:02 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char	*error)
{
	printf("Error\n%s\n", error);
}

void	ft_error(char *error)
{
	print_error(error);
	exit(-1);
}

void	free_error(char *error, t_param *data)
{
	int quit;

	quit = 0;
	if (data->err)
	{
		print_error(error);
		free(error);
		quit = 1;
	}
	if (data->prev_line)
		free(data->prev_line);
	free(data);
	if (quit)
		exit(-1);
	ft_error(error);
}

char	*ft_strerror(int no)
{
	if (no == -1)
		return (ft_strdup("resolution line is invalid"));
	else
		return (NULL);
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
	if (!(*line == ' '))
		return(-1);
	while(*line == ' ')
		line++;
	if (*line == '+' || *line == '-' || !(data->x = ft_atoi(line)))
		return(-1);
	while (ft_isdigit(*line))
		line++;
	if (!(*line == ' '))
		return (-1);
	while(*line == ' ')
		line++;
	if (*line == '+' || *line == '-' || !(data->y = ft_atoi(line)))
		return (-1);
	while (ft_isdigit(*line))
		line++;
	while(*line)
	{
		if (!(*line == ' '))
		{
			return (-1);
		}
	}
	return(1);
}

int	get_info(char *line, t_param *data)
{
	int		ret;

	if (!ft_strncmp(line, "R", 1))
		ret = parse_resolution(line, data);
	/*else if (!ft_strncmp(line + 1, "NO", 2))
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
		//C*/
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

	while (ret && ret > 0  && get_next_line(fd, &line))
	{
		if (!(trim = ft_strtrim(line, " ")))
		{
			data->err = errno;
			return (0);
		}
		ret = get_info(trim, data);
		if (!ret)
			data->prev_line = ft_strdup(line);
		if (ret < 0)
			data->err = ret;
		free(trim);
		free(line);
	}
	return (ret);
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
	if (parse_arg(fd, data) < 0)
	{
		close(fd);
		free_error(ft_strerror(data->err) ,data);
	}
	close(fd);
	return (1); 
}
