#include <mlx.h>
#include <string.h>
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

int		open_mlx_text(t_mlx *m, t_text *t)
{
	if (!(t->img = mlx_xpm_file_to_image(m->ptr, t->path, &t->w, &t->h)))
		return (0);
	return (1);
}

int		open_text(t_mlx *m, t_cub3d *d)
{
	if (open_mlx_text(m, &d->text_sprite)
	&& open_mlx_text(m, &d->text_n)
	&& open_mlx_text(m, &d->text_s)
	&& open_mlx_text(m, &d->text_w)
	&& open_mlx_text(m, &d->text_e))
		return (1);
	return (0);
}

int		mlx_setup(t_mlx *m, t_cub3d *d)
{
	if (!(m->ptr = mlx_init()))
		free_data_err("fail to init mlx", NULL, d);
	adjust_res(m, d);
	if (!(open_text(m, d)))
		free_data_err("fail to open textures", NULL, d);
	if (!(m->win = mlx_new_window(m->ptr, (int)d->def.x, (int)d->def.y, "cub3D")))
		free_data_err("fail to create window", NULL, d);
	if (!(m->img = mlx_new_image(m->ptr, (int)d->def.x, (int)d->def.y)))
		free_data_err("fail to create image", NULL, d);
	m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->length, &m->endian);
	return (1);
}
