#include "../includes/render.h"
#include <stdio.h>
#include <math.h>

static int find_h_intersect(t_ray *ray, t_cub3d *data)
{
	if (ray->up != 0)
	{
		if (ray->up == 1)
		{
			ray->intersect.y = floor(data->pos.y);
			ray->step_y = -1;
		}
		else
		{
			ray->intersect.y = floor(data->pos.y) + 1;
			ray->step_y = 1;
		}
		if (ray->left != 0)
		{
			ray->intersect.x = data->pos.x + (data->pos.y - ray->intersect.y) / tan(ray->ray_angle);
			ray->step_x = (1 / tan(ray->ray_angle)) * ray->up;
		}
		else
		{
			ray->intersect.x = data->pos.x;
			ray->step_x = 0;
		}
		return (check_hit_loop(ray, data, &check_h_hit));
	}
	return (0);
}

static int	find_v_intersection(t_ray *ray, t_cub3d *data)
{
	if (ray->left != 0)
	{
		if (ray->left == 1)
		{
			ray->intersect.x = floor(data->pos.x);
			ray->step_x = -1;
		}
		else
		{
			ray->intersect.x = floor(data->pos.x) + 1;
			ray->step_x = 1;
		}
		ray->intersect.y = data->pos.y + (data->pos.x - ray->intersect.x) * tan(ray->ray_angle);
		ray->step_y = tan(ray->ray_angle) * ray->left;
		return (check_hit_loop(ray, data, &check_v_hit));
	}
	return (0);
}

static void getTextDir(t_ray *ray)
{
	if (ray->dir == 1)
	{
		if (ray->up == 1)
			ray->text_dir = 1;
		else 
			ray->text_dir = 3;
	}
	else
	{
		if (ray->left == 1)
			ray->text_dir = 0;
		else 
			ray->text_dir = 2;
	}
}

static void find_nearest_intersection(t_ray *ray, t_cub3d *data)
{
	double distH;
	double distV;

    distH = sqrt(pow(data->pos.x - ray->h_intersect.x, 2) + pow(data->pos.y - ray->h_intersect.y, 2));
	distV = sqrt(pow(data->pos.x - ray->v_intersect.x, 2) + pow(data->pos.y - ray->v_intersect.y, 2));
	if (ray->h_intersect.x != -1)
	{
        if (ray->v_intersect.x == -1 || distH < distV)
		{
			ray->intersect.x = ray->h_intersect.x;
			ray->intersect.y = ray->h_intersect.y;
			ray->dir = 1;
		}
	}
    getTextDir(ray);
}

void    find_intersection(t_ray *ray, t_cub3d *data)
{
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
}