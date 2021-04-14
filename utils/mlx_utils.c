#include "mlx.h"
#include <string.h>
#include "struct.h"
#include "error.h"

/*static void	adjust_res(t_mlx *mlx, t_cub3d *data)
{
	int	screen_x;
	int screen_y;

	mlx_get_screen_size(mlx->ptr, &screen_x, &screen_y);
	if (screen_x < data->def.x)
		data->def.x = screen_x;
	if (screen_y < data->def.y)
		data->def.y = screen_y;
}*/

static int	open_mlx_text(t_mlx *m, t_text *t)
{
	if (!(t->img.img = mlx_xpm_file_to_image(m->ptr, t->path, &t->w, &t->h)))
		return (0);
	t->img.addr = mlx_get_data_addr(t->img.img, &t->img.bpp, &t->img.length, &t->img.endian);
	return (1);
}

static int	open_text(t_mlx *m, t_cub3d *d)
{
	if (open_mlx_text(m, &d->text_sprite)
		&& open_mlx_text(m, &d->text_n)
		&& open_mlx_text(m, &d->text_s)
		&& open_mlx_text(m, &d->text_w)
		&& open_mlx_text(m, &d->text_e))
		return (1);
	return (0);
}

static int	setup_frame(t_mlx *m, t_cub3d *d, t_img *f)
{
	if (!( f->img = mlx_new_image(m->ptr, (int)d->def.x, (int)d->def.y)))
		return (0);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->length, &f->endian);
	return (1);
}

void		mlx_setup(t_mlx *m, t_cub3d *d)
{
	if (!(m->ptr = mlx_init()))
		free_data_err("fail to init mlx", NULL, d);
	//adjust_res(m, d);
	if (!(open_text(m, d)))
		free_data_err("fail to open textures", NULL, d);
	if (!(m->win = mlx_new_window(m->ptr, (int)d->def.x, (int)d->def.y, "cub3D")))
		free_data_err("fail to create window", NULL, d);
	if (!(setup_frame(m, d, &m->frame)))
		free_data_err("fail to create image", NULL, d);
}
