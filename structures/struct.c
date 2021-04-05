#include "../includes/cub3d.h"

void	init_point(t_point *point)
{
	point->x = -1;
	point->y = -1;
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

void	init_ray(t_ray *ray)
{
	ray->up = 0;
	ray->left = 0;
	init_point(&ray->h_i);
	init_point(&ray->v_i);
	init_point(&ray->i);
	ray->step_x = 0;
	ray->step_y = 0;
	ray->angle = 0;
	ray->text_dir = 0;
	ray->dir = 0;
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
	temp->f[0] = -1;
	temp->f[1] = -1;
	temp->f[2] = -1;
	temp->c[0] = -1;
	temp->c[1] = -1;
	temp->c[2] = -1;
	temp->map.h = 0;
	temp->map.w = 0;
	temp->map.map = NULL;
}

void	init_cub3d(t_cub3d *data)
{
	init_mlx(&data->mlx);
	init_point(&data->pos);
	init_point(&data->def);
	data->map.h = 0;
	data->map.w = 0;
	data->map.map = NULL;
	data->angle = 0;
	init_ray(&data->ray);
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
