#include "struct.h"

void	init_point(t_point *point)
{
	point->x = -1;
	point->y = -1;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->frame.img = NULL;
	mlx->frame.addr = NULL;
	mlx->frame.bpp = 0;
	mlx->frame.length = 0;
	mlx->frame.endian = 0;
}

void	init_text(t_text *t)
{
	t->path = NULL;
	t->w = 0;
	t->h = 0;
	t->img.img = NULL;
	t->img.addr = NULL;
	t->img.bpp = 0;
	t->img.length = 0;
	t->img.endian = 0;
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


