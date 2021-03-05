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

#include "./includes/cub3d.h"

int		main(int argc, char **argv)
{
	char *test;
	t_cub3D *data;

	test = NULL;
	free(test);
	if (argc == 1 || argc > 3)
		ft_error("usage: cub3d [--save] file");
	if (argc == 3 && !(ft_strcmp(argv[1], "--save")))
		ft_error("usage: cub3d [--save] file");
	if (argc == 2 || argc == 3)
		data = cub_parser(argv[1]);
	printf("done\n");
	return (0);
}
