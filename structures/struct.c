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
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->bpp = 0;
	mlx->length = 0;
	mlx->endian = 0;
}

void	init_text(t_text *t)
{
	t->path = NULL;
	t->w = 0;
	t->h = 0;
	t->img = NULL;
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


