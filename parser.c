/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:08:01 by valentin          #+#    #+#             */
/*   Updated: 2020/09/21 20:55:35 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void ft_error(char *error)
{
	printf("Error\n%s\n", error);
	exit(-1);
}

int check_path(char *path)
{
	size_t len;

	len = ft_strlen(path);
	if (ft_strcmp(path + (len - 4), ".cub"))
		return (0);
	return(1);
}

int	get_info(char *line)
{
	char	*trim;
	int		ret;

	printf("%s\n", line);
	ret = 1;
	if (!(trim = ft_strtrim(line, " ")))
		ft_error(strerror(errno));
	/*if (!ft_strncmp(trim, "R", 1))
		//R
	else if (!ft_strncmp(trim, "NO", 2))
		//NO
	else if (!ft_strncmp(trim, "SO", 2))
		//SO
	else if (!ft_strncmp(trim, "WE", 2))
		//WE
	else if (!ft_strncmp(trim, "EA", 2))
		//EA
	else if (!ft_strncmp(trim, "F", 1))
		//F
	else if (!ft_strncmp(trim, "C", 1))
		//C
	else if(ft_strcmp(trim, "\0"))
		ret = 0;*/
	if(!ft_strncmp(trim, "1", 1))
		ret = 0;
free(trim);
return (ret);
}

int	get_map(char *line)
{
	printf("%s\n", line);
	return (1);
}

int	cub_parser(char *path)
{
	int		fd;
	char	*line;
	int		is_map;

	is_map = 0;
	if(!check_path(path))
		ft_error("file must end with .cub");
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error(strerror(errno));
	while(get_next_line(fd, &line))
	{
		if(is_map || !get_info(line))
		{	
			is_map = 1;
			if (!get_map(line))
			{
				close(fd);
				free(line);
				ft_error("invalid file syntax");
			}
		}
		free(line);
	}
	close(fd);
	return 1;
}
