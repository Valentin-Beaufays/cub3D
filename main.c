/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:03:23 by valentin          #+#    #+#             */
/*   Updated: 2020/09/21 19:20:41 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cub_parser(char *path);

int	main(int argc, char **argv)
{
	if (argc == 2)
		cub_parser(argv[1]);
	return (0);
}
