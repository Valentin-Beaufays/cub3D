#include "../includes/cub3d.h"

static void getRayDir(double angle, int *up, int *left)
{
	if (angle > 0 && angle < M_PI)
		*up = 1;
	else if (angle > M_PI)
		*up = -1;
    else
        *up = 0;
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		*left = 1;
	else if (angle < M_PI / 2 || angle > 3 * M_PI / 2)
		*left = -1;
    else
        *left = 0;
}

int    render(t_cub3d *data)
{
    t_ray	ray;
	int		x;

    init_ray(&ray);
    x = 0;
    ray.rayAngle = round_rad(data->angle + (data->fov / 2));
    while (x < (int)data->def.x)
    {
        getRayDir(ray.rayAngle, &ray.up, &ray.left);
        init_point(&ray.h_intersect);
        init_point(&ray.v_intersect);
	    ray.dir = 0;
        find_intersection(&ray, data);
        print_column(&ray, data, x);
        ray.rayAngle = round_rad(ray.rayAngle - data->stepRad);
        x++;
    }
    mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img, 0, 0);
    return (0);
}