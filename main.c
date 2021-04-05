/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:03:23 by valentin          #+#    #+#             */
/*   Updated: 2020/09/23 15:37:08 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "struct.h"
#include "parser.h"
#include "game.h"
#include "error.h"

static void print_map(t_map *map)
{
	printf("map:\nh: %ld, w: %ld\n\n", map->h, map->w);
	for(size_t i = 0; i < map->h; i++)
	{
		printf("%s\n", map->map[i]);
	}
}

static void print_data(t_cub3d *data)
{
	printf("resolution: %f x %f\n", data->def.x, data->def.y);
	printf("pos: (%f;%f), angle: %f°\n", data->pos.x, data->pos.y, data->angle);
	printf("n: %s, s: %s, e: %s, w: %s, sprite: %s\n", data->text_n, data->text_s, data->text_e, data->text_w, data->text_sprite);
	printf("f_color: %i\nc_color: %i\n", data->color_floor, data->color_ceil);
	print_map(&data->map);
}

int		main(int argc, char **argv)
{
	char	*test;
	t_cub3d	*data;

	test = NULL;
	free(test);
	if (argc == 1 || argc > 3)
		ft_error("usage: cub3d [--save] file");
	if (argc == 3 && !(ft_strcmp(argv[1], "--save")))
		ft_error("usage: cub3d [--save] file");
	if (argc == 2 || argc == 3)
		data = cub_parser(argv[1]);
	print_data(data);
	game_loop(data);
	printf("done\n");
	return (0);
}
