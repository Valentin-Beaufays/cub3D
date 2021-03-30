#include "../includes/render.h"

char Map[mapHeight][mapWidth]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1}
};

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

int check_hit_loop(t_ray *ray, t_cub3d *data, int (*c_h)(t_ray *ray, t_cub3d *data))
{
	int	hit;

	hit = (*c_h)(ray, data);
	while (!hit)
	{
		ray->intersect.x += ray->stepX;
		ray->intersect.y += ray->stepY;
		hit = (*c_h)(ray, data);
	}
    if (hit == -1)
	    return (0);
    return (1);
}