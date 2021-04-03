#include "../includes/cub3d.h"

void	init_point(t_point *point)
{
	point->x = -1;
	point->y = -1;
}

void	init_map(t_map *map)
{
	map->h = 0;
	map->w = 0;
	map->map = NULL;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->bpp = 0;
	mlx->length = 0;
	mlx->endian = 0;
}

void	init_temp(t_temp *temp, int fd)
{
	temp->fd = fd;
	temp->line = NULL;
	temp->trim = NULL;
	temp->x = 0;
	temp->y = 0;
	temp->north = NULL;
	temp->south = NULL;
	temp->west = NULL;
	temp->east = NULL;
	temp->sprite = NULL;
	temp->floor[0] = -1;
	temp->floor[1] = -1;
	temp->floor[2] = -1;
	temp->ceiling[0] = -1;
	temp->ceiling[1] = -1;
	temp->ceiling[2] = -1;
	init_map(&temp->map);
}

void	init_cub3d(t_cub3d *data)
{
	init_mlx(&data->mlx);
	init_point(&data->pos);
	init_point(&data->def);
	init_map(&data->map);
	data->angle = 0;
	data->fov = round_rad(deg2rad(60));
	data->step_rad = 0;
	data->text_sprite = NULL;
	data->text_n = NULL;
	data->text_s = NULL;
	data->text_e = NULL;
	data->text_w = NULL;
	data->color_ceil = 0;
	data->color_floor = 0;
}

void init_ray(t_ray *ray)
{
	ray->up = 0;
	ray->left = 0;
	init_point(&ray->h_intersect);
	init_point(&ray->v_intersect);
	init_point(&ray->intersect);
	ray->step_x = 0;
	ray->step_y = 0;
	ray->ray_angle = 0;
	ray->text_dir = 0;
	ray->dir = 0;
}
