#include "../includes/render.h"

int	check_h_hit(t_ray *ray, t_map *map)
{
	int	up;

	up = 0;
	if (ray->up == 1)
		up = 1;
	if (ray->i.x >= 0 && ray->i.y >= 0 &&
		ray->i.x < map->w && ray->i.y < map->h)
	{
		if (map->map[(int)ray->i.y - up][(int)ray->i.x] == 1)
			return (1);
		else
			return (0);
	}
	return (-1);
}

int	check_v_hit(t_ray *ray, t_map *map)
{
	int	left;

	left = 0;
	if (ray->left == 1)
		left = 1;
	if (ray->i.x >= 0 && ray->i.y >= 0 &&
		ray->i.x < map->w && ray->i.y < map->h)
	{
		if (map->map[(int)ray->i.y][(int)ray->i.x - left] == 1)
			return (1);
		else
			return (0);
	}
	return (-1);
}

int	check_hit_loop(t_ray *ray, t_cub3d *data, int (*f)(t_ray *ray, t_map *map))
{
	int	hit;

	hit = (*f)(ray, &data->map);
	while (!hit)
	{
		ray->i.x += ray->step_x;
		ray->i.y += ray->step_y;
		hit = (*f)(ray, &data->map);
	}
	if (hit == -1)
		return (0);
	return (1);
}
