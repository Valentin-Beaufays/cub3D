#include <mlx.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
#include "utils.h"
#include "error.h"
#include "struct.h"

#include <stdio.h>

static void	fill_img(t_mlx *m, t_img *new, t_text *t)
{
	int		y;
	int		x;
	int 	old_x;
	int		old_y;
	int		color;
	double	ratio_h;
	double	ratio_w;
	
	y = 0;
	x = 0;
	ratio_h = (double)t->h / (double)new->h;
	ratio_w = (double)t->w / (double)new->w;
	while (y < new->h)
	{
		x = 0;
		while (x < new->w)
		{
			old_x = (int)(floor((double)x) * ratio_w);
			old_y = (int)(floor((double)y) * ratio_h);
			color = ft_mlx_pixel_get(&t->img, old_x, old_y);
			ft_mlx_pixel_put(m, new, x, y, color);
			x++;
		}
		y++;
	}
}

t_img	*resize_image(t_cub3d *d, t_mlx *m, t_text *t, int w, int h)
{
	t_img	*n;

	if (!(n = malloc(sizeof(t_img))))
		free_data_err(strerror(errno), NULL, d);
	n->h = h;
	n->w = w;
	if (!(n->img = mlx_new_image(m->ptr, w, h)))
	{
		free(n);
		free_data_err("mlx fail to create image", NULL, d);
	}
	n->addr = mlx_get_data_addr(n->img, &n->bpp, &n->length, &n->endian);
	fill_img(m, n, t);
	return (n);
}
