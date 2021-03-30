#include "../libft/libft.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <math.h>
#include <mlx.h>

#define screenW 480
#define screenH 480
#define mapWidth 13
#define mapHeight 3
#define SIZE 64

char Map[mapHeight][mapWidth]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void copy_map(t_map *map)
{
    map->map = Map;
    map->h = mapHeight;
    map->w = mapWidth;
}

int	rgb_to_int(int r, int g, int b)
{
	return (((256*256) * r) + (256 * g) + b);
}

double  deg2rad(double deg)
{
    return (deg * M_PI / 180);
}

double  rad2deg(double rad)
{
    return (rad * 180 / M_PI);
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

double  round_rad(double rad)
{
    while (rad > 2 * M_PI)
        rad -= 2 * M_PI;
    while (rad < 0)
        rad += 2 * M_PI;
    return (rad);
}

//actual code

int	check_h_hit(t_ray *ray, t_cub3d *data)
{
    int up;
    up = 0;
    if  (ray->up == 1)
        up = 1;
	if (ray->intersect.x >= 0 && ray->intersect.y >= 0 && ray->intersect.x < data->map.w && ray->intersect.y < data->map.h)
	{
		if (Map[(int)ray->intersect.y - up][(int)ray->intersect.x] == 1)
            return (1);
        else
            return (0);
	}
	return (-1);
}

int	check_v_hit(t_ray *ray, t_cub3d *data)
{
    int left;
    left = 0;
    if (ray->left == 1)
        left = 1;
	if (ray->intersect.x >= 0 && ray->intersect.y >= 0 && ray->intersect.x < data->map.w && ray->intersect.y < data->map.h)
	{
		if (Map[(int)ray->intersect.y][(int)ray->intersect.x - left] == 1)
            return (1);
        else
            return (0);
	}
	return (-1);
}

int check_hit_loop(t_ray *ray, t_cub3d *data, int (*check_hit)(t_ray *ray, t_cub3d *data))
{
	int	hit;

	hit = check_hit(ray, data);
	while (!hit)
	{
		ray->intersect.x += ray->stepX;
		ray->intersect.y += ray->stepY;
		hit = (*check_hit)(ray, data);
	}
    if (hit == -1)
	    return (0);
    return (1);
}

int find_h_intersect(t_ray *ray, t_cub3d *data)
{
	if (ray->up != 0)
	{
		if (ray->up == 1)
		{
			ray->intersect.y = floor(data->pos.y);
			ray->stepY = -1;
		}
		else
		{
			ray->intersect.y = floor(data->pos.y) + 1;
			ray->stepY = 1;
		}
		if (ray->left != 0)
		{
			ray->intersect.x = data->pos.x + (data->pos.y - ray->intersect.y) / tan(ray->rayAngle);
			ray->stepX = (1 / tan(ray->rayAngle)) * ray->up;
		}
		else
		{
			ray->intersect.x = data->pos.x;
			ray->stepX = 0;
		}
        //printf("%f %f %f %f\n", ray->intersect.x, ray->intersect.y, data->pos.x, data->pos.y);
		return (check_hit_loop(ray, data, &check_h_hit));
	}
	return (0);
}

int	find_v_intersection(t_ray *ray, t_cub3d *data)
{
	if (ray->left != 0)
	{
		if (ray->left == 1)
		{
			ray->intersect.x = floor(data->pos.x);
			ray->stepX = -1;
		}
		else
		{
			ray->intersect.x = floor(data->pos.x) + 1;
			ray->stepX = 1;
		}
		ray->intersect.y = data->pos.y + (data->pos.x - ray->intersect.x) * tan(ray->rayAngle);
		ray->stepY = tan(ray->rayAngle) * ray->left;
        printf("go\n");
		return (check_hit_loop(ray, data, &check_v_hit));
	}
	return (0);
}

void find_nearest_intersection(t_ray *ray, t_cub3d *data)
{
	double distH;
	double distV;
	if (ray->h_intersect.x != -1)
	{
		distH = sqrt(pow(data->pos.x - ray->h_intersect.x, 2) + pow(data->pos.y - ray->h_intersect.y, 2));
		distV = sqrt(pow(data->pos.x - ray->v_intersect.x, 2) + pow(data->pos.y - ray->v_intersect.y, 2));
		printf("%f %f\n", distH, distV);
        if (ray->v_intersect.x == -1 || distH < distV)
		{
			ray->intersect.x = ray->h_intersect.x;
			ray->intersect.y = ray->h_intersect.y;
		}
	}
}

void    find_intersection(t_ray *ray, t_cub3d *data)
{
    getRayDir(ray->rayAngle, &ray->up, &ray->left);
    printf("angle rad: %f, up: %d, left: %d\n", ray->rayAngle, ray->up, ray->left);
    if (find_h_intersect(ray, data))
    {
		ray->h_intersect.x = ray->intersect.x;
		ray->h_intersect.y = ray->intersect.y;
	}
    if (find_v_intersection(ray, data))
	{
		ray->v_intersect.x = ray->intersect.x;
		ray->v_intersect.y = ray->intersect.y;
	}
    find_nearest_intersection(ray, data);
    printf("h_intersect: (%f;%f)\n", ray->h_intersect.x, ray->h_intersect.y);
    printf("v_intersect: (%f;%f)\n", ray->v_intersect.x, ray->v_intersect.y);
    printf("intersect: (%f;%f)\n", ray->intersect.x, ray->intersect.y);
}

void    render(t_cub3d *data)
{
    t_ray	ray;
	int		x;

    init_ray(&ray);
    x = 0;
    ray.rayAngle = data->angle + (data->fov / 2);
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
	data.angle = round_rad(deg2rad(10));
	data.fov = round_rad(deg2rad(60));
	data.stepRad = data.fov / data.def.x;
    data.color_ceil = rgb_to_int(0, 191, 255);
	data.color_floor = rgb_to_int(204, 102, 0);
    render(&data);
}