/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:03:23 by valentin          #+#    #+#             */
/*   Updated: 2020/09/22 14:21:06 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cub_parser(char *path);

int	main(int argc, char **argv)
{
	if (argc == 2 || argc == 3)
		if (argc == 3 && !(ft_strcmp(argv[1], "--save")))
			ft_error(invalid argument)
		cub_parser(argv[1]);
	return (0);
}

/*
 * ->
