#include "cub3d.h"

double ft_abs(double val)
{
	if (val < 0)
		val *= -1;
	return (val);
}

static void	get_step(t_cub3d *data, double *step_x, double *step_y)
{
	double	dist_x;
	double	dist_y;

	dist_x = ft_abs(data->ray.i.x - data->pos.x);
	dist_y = ft_abs(data->ray.i.y - data->pos.y);
	if (data->ray.dir == 1)
	{
		*step_y = sin(data->angle) * 0.1;
		if (ft_abs(dist_y) <= ft_abs(*step_y))
			*step_y = dist_y - 0.05 * data->ray.up;
		*step_x = *step_y / tan(data->angle);
		if (ft_abs(dist_x) <= ft_abs(*step_x))
			*step_x = dist_x - 0.05 * data->ray.left;
	}
	else
	{
		*step_x = cos(data->angle) * 0.1;
		if (ft_abs(dist_x) <= ft_abs(*step_x))
			*step_x = dist_x - 0.05 * data->ray.left;
		*step_y = *step_x * tan(data->angle);
		if (ft_abs(dist_y) <= ft_abs(*step_y))
			*step_y = dist_y - 0.05 * data->ray.up;
	}
}

int key_hook(int key, t_cub3d *data)
{
	double	step_x;
	double	step_y;

	if (key == LEFT)
		data->angle = round_rad(data->angle + 0.05);
	else if (key == RIGHT)
		data->angle = round_rad(data->angle - 0.05);
	if (key == UP)
	{
		find_intersection(&data->ray, data);
		get_step(data, &step_x, &step_y);
		step_x = data->pos.x + step_x;
		step_y = data->pos.y - step_y;
		if (data->map.map[(int)step_y][(int)step_x] != 1)
		{
			data->pos.x = step_x;
			data->pos.y = step_y;
		}
	}
	if (key == DOWN)
	{
		data->ray.angle += M_PI;
		find_intersection(&data->ray, data);
		get_step(data, &step_x, &step_y);
		step_x = data->pos.x - step_x;
		step_y = data->pos.y + step_y;
		if (data->map.map[(int)step_y][(int)step_x] != 1)
		{
			data->pos.x = step_x;
			data->pos.y = step_y;
		}
	}
    render(data);
    return (0);
}

void	game_loop(t_cub3d *data)
{
	data->mlx.ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.ptr, (int)data->def.x,(int)data->def.y, "raycaster");
	data->mlx.img = mlx_new_image(data->mlx.ptr, (int)data->def.x,(int)data->def.y);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp, &data->mlx.length, &data->mlx.endian);
	mlx_key_hook(data->mlx.win, &key_hook, data);
	mlx_loop_hook(data->mlx.ptr, &render, data);
	mlx_loop(data->mlx.ptr);
}