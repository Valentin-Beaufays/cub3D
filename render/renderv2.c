#include "../libft/libft.h"
#include "../includes/render.h"
#include <stdio.h>
#include <math.h>
#include <mlx.h>

//utils

int	rgb_to_int(int r, int g, int b)
{
	return (((256*256) * r) + (256 * g) + b);
}

void getRayDir(double angle, int *up, int *left)
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

//actual code

void    render(t_cub3d *data)
{
    t_ray	ray;
	int		x;

    init_ray(&ray);
    x = 0;
    ray.rayAngle = round_rad(data->angle + (data->fov / 2));
    while (x < 1)//data->def.x)
    {
        find_intersection(&ray, data);
        //if (x == 0 || x == data->def.x - 1)
            printf ("ray angle: %f°\n", rad2deg(ray.rayAngle));
        ray.rayAngle = round_rad(ray.rayAngle - data->stepRad);
        x++;
    }
}

int main()
{
    t_cub3d data;

	data.def.x = screenW;
	data.def.y = screenH;
    data.pos.x = 1.5; 
    data.pos.y = 1.5;  //x and y start position
    data.map.h = mapHeight;
    data.map.w = mapWidth;
    printf("pos: (%f;%f)\n", data.pos.x, data.pos.y);
	data.angle = round_rad(deg2rad(150));
	data.fov = round_rad(deg2rad(60));
	data.stepRad = data.fov / data.def.x;
    data.color_ceil = rgb_to_int(0, 191, 255);
	data.color_floor = rgb_to_int(204, 102, 0);
    render(&data);
}
