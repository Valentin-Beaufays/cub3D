#include <mlx.h>
#include "struct.h"
#include "error.h"

void	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->length + x * (mlx->bpp / 8));
	*(unsigned int*)dst = mlx_get_color_value(mlx->ptr, color);
}

void	adjust_res(t_mlx *mlx, t_cub3d *data)
{
	int	screen_x;
	int screen_y;

	mlx_get_screen_size(mlx->ptr, &screen_x, &screen_y);
	if (screen_x < data->def.x)
		data->def.x = screen_x;
	if (screen_y < data->def.y)
		data->def.y = screen_y;
}

int		mlx_setup(t_mlx *m, t_cub3d *d)
{
	if (!(m->ptr = mlx_init()))
		return (0);
	adjust_res(m, d);
	if (!(m->win = mlx_new_window(m->ptr, (int)d->def.x, (int)d->def.y, "cub3D")))
		return (0);
	if (!(m->img = mlx_new_image(m->ptr, (int)d->def.x, (int)d->def.y)))
		return (0);
	if (!(m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->length, &m->endian)))
		return (0);
}
