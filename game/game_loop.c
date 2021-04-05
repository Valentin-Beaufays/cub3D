#include "cub3d.h"

double ft_abs(double val)
{
	if (val < 0)
		val *= -1;
	return (val);
}

int key_hook(int key, t_cub3d *data)
{
	if (key == LEFT)
		data->angle = round_rad(data->angle + 0.05);
	else if (key == RIGHT)
		data->angle = round_rad(data->angle - 0.05);

	double	move_x;
	double	move_y;
	double	dist_x;
	double	dist_y;
	double	step_x;
	double	step_y;

	find_intersection(&data->ray, data);
	step_x = ft_abs(cos(data->angle) * 0.2);
	step_y = ft_abs(sin(data->angle) * 0.2);
	dist_x = ft_abs(data->ray.i.x - data->pos.x);
	dist_y = ft_abs(data->ray.i.y - data->pos.y);
	if (key == UP)
	{
		data->ray.angle = data->angle;
		if (dist_x <= step_x)
			step_x = dist_x - 0.1;
		if (dist_y <= step_y)
			step_y = dist_y - 0.1;
		if (step_x < 0)
			step_x = 0;
		if (step_y < 0)
			step_y = 0;
		data->pos.x -= step_x * data->ray.left;
		data->pos.y -= step_y * data->ray.up;
		printf("pos:(%f;%f), new:(%f;%f), wall: (%f;%f) dist_x: %f, dist_y: %f, ste_x: %f, step_y: %f\n", data->pos.x, data->pos.y, move_x, move_y, data->ray.i.x, data->ray.i.y, dist_x, dist_y, step_x, step_y);
		printf("angle: %f°\n", rad2deg(data->angle));
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