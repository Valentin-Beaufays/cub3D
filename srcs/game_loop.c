/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:22:58 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:23:01 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include "render.h"
#include "key.h"
#include "struct.h"
#include "utils.h"
#include "error.h"
#include "game.h"

static void	get_step(t_cub3d *data, double *step_x, double *step_y)
{
	double	dist_x;
	double	dist_y;

	dist_x = ft_abs(data->ray.i.x - data->pos.x);
	dist_y = ft_abs(data->ray.i.y - data->pos.y);
	if (data->ray.dir == 1)
	{
		*step_y = sin(data->angle) * 0.2;
		if (ft_abs(dist_y) <= ft_abs(*step_y))
			*step_y = dist_y - (sin(data->ray.angle) * 0.2 * -1);
		*step_x = cos(data->angle) * 0.2;
		if (ft_abs(dist_x) <= ft_abs(*step_x))
			*step_x = dist_x - (cos(data->ray.angle) * 0.2 * -1);
	}
	else
	{
		*step_x = cos(data->angle) * 0.2;
		if (ft_abs(dist_x) <= ft_abs(*step_x))
			*step_x = dist_x - (cos(data->ray.angle) * 0.2 * -1);
		*step_y = sin(data->angle) * 0.2;
		if (ft_abs(dist_y) <= ft_abs(*step_y))
			*step_y = dist_y - (sin(data->ray.angle) * 0.2 * -1);
	}
}

static void	update_pos(int key, t_cub3d *data)
{
	double	step_x;
	double	step_y;

	data->ray.angle = data->angle;
	if (key == DOWN)
		data->ray.angle = round_rad(data->ray.angle + M_PI);
	find_intersection(&data->ray, data);
	get_step(data, &step_x, &step_y);
	if (key == DOWN)
	{
		step_x = data->pos.x - step_x;
		step_y = data->pos.y + step_y;
	}
	else
	{
		step_x = data->pos.x + step_x;
		step_y = data->pos.y - step_y;
	}
	if (data->map.map[(int)step_y][(int)step_x] != 1)
	{
		data->pos.x = step_x;
		data->pos.y = step_y;
	}
}

static int	key_hook(int key, t_cub3d *data)
{
	if (key == LEFT)
		data->angle = round_rad(data->angle + 0.1);
	else if (key == RIGHT)
		data->angle = round_rad(data->angle - 0.1);
	if (key == UP || key == DOWN)
	{
		update_pos(key, data);
	}
	render(data);
	return (0);
}

static int	exit_hook(t_cub3d *data)
{
	free_data(data);
	exit(0);
}

void	game_loop(t_cub3d *data)
{
	mlx_setup(&data->mlx, data);
	if (data->save == 1)
	{
		data->save = 0;
		render(data);
		save_bmp(&data->mlx.fra, data);
	}
	mlx_hook(data->mlx.w, 33, 1L << 17, &exit_hook, data);
	mlx_key_hook(data->mlx.w, &key_hook, data);
	mlx_loop_hook(data->mlx.p, &render, data);
	mlx_loop(data->mlx.p);
}
