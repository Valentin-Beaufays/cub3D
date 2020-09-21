/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:46:13 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/09/21 15:22:23 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_param
{
	void *mlx_ptr;
	void *win_ptr;
	int x;
	int y;

}				t_param;

int handle_loop(int key, t_param *param)
{
	int x = 0;
	int y = 0;
	int color = 255;
	(void) key;
	while (y < param->y)
	{
		while (x < param->x)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	return(0);
}

int	main()
{
	t_param param;
	int (*f)();

	param.x = 1280;
	param.y = 720;
	f = &handle_loop;
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.x, param.y, "cub3D");
	mlx_key_hook(param.win_ptr, f, &param);
	mlx_loop(param.mlx_ptr);
	return(0);
}
