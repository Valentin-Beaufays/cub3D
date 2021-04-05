#include "../includes/cub3d.h"

void	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->length + x * (mlx->bpp / 8));
	*(unsigned int*)dst = mlx_get_color_value(mlx->ptr, color);
}

void	mlx_setup(t_mlx *m, t_cub3d *d)
{
	m->ptr = mlx_init();
	m->win = mlx_new_window(m->ptr, (int)d->def.x, (int)d->def.y, "raycaster");
	m->img = mlx_new_image(m->ptr, (int)d->def.x, (int)d->def.y);
	m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->length, &m->endian);
}
