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

int		main(int argc, char **argv)
{
	char	*test;
	t_cub3d	*data;

	test = NULL;
	free(test);
	if (argc <= 1 || argc > 3)
		ft_error("usage: cub3d [--save] file");
	if (argc == 3 && ft_strcmp(argv[1], "--save"))
		ft_error("usage: cub3d [--save] file");
	if (argc == 2)
		data = cub_parser(argv[1]);
	else if (argc == 3)
	{
		data = cub_parser(argv[2]);
		data->save = 1;
	}
	game_loop(data);
	return (0);
}
