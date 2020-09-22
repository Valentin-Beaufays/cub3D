/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:03:23 by valentin          #+#    #+#             */
/*   Updated: 2020/09/22 15:49:02 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_param(t_param **data)
{
	if (!(*data = malloc(sizeof(t_param))))
		ft_error(strerror(errno));
	(*data)->x = 0;
	(*data)->y = 0;
}

void	init_data(char *path)
{
	t_param	*data;

	init_param(&data);
	cub_parser(path, data);
}

int		main(int argc, char **argv)
{
	if (argc == 1 || argc > 3)
		ft_error("usage: cub3d [--save] file");
	if (argc == 3 && !(ft_strcmp(argv[1], "--save")))
		ft_error("invalid argument");
	if (argc == 2 || argc == 3)
	init_data(argv[argc - 1]);
	return (0);
}
