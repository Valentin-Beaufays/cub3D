#include <mlx.h>
#include <stdio.h>
#include "render.h"
#include "struct.h"
#include "utils.h"

int			render(t_cub3d *data)
{
	int		x;

	x = 0;
	data->ray.angle = round_rad(data->angle + (data->fov / 2));
	while (x < (int)data->def.x)
	{
		find_intersection(&data->ray, data);
		print_column(&data->ray, data, x);
		data->angle_buf[x] = round_rad(data->ray.angle);
		data->ray.angle = round_rad(data->ray.angle - data->step_rad);
		x++;
	}
	//print sprite
	t_sprite	*cur;
	cur = data->sprite;
	while (cur)
	{
		printf("sprite: (%f;%f) dist: %f, angle:%f\n", cur->pos.x, cur->pos.y, cur->dist, rad2deg(cur->angle));
		cur = cur->next;
	}
	free_sprite(data->sprite);
	data->sprite = NULL;
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
