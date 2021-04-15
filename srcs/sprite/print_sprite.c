#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include "struct.h"
#include "sprite.h"
#include "utils.h"

static void	print_sprite_col(t_cub3d *d, t_img *img, int x_img, int x)
{
	int	y;
	int	y_img;
	int start;
	int color;

	y = 0;
	y_img = 0;
	start = (d->def.y / 2) - (img->h / 2);
	while (y < start)
		y++;
	while (y < 0)
	{
		y++;
		y_img++;
	}
	while (y_img < img->h && y < d->def.y)
	{
		color = ft_mlx_pixel_get(img, x_img, y_img);
		if (color > 0)
			ft_mlx_pixel_put(&d->mlx, &d->mlx.frame, x, y, color);
		y++;
		y_img++;
	}
}

static void	print_sprite_to_screen(t_cub3d *d, t_img *img, int x, double dist)
{
	int	x_img;

	x_img = 0;
	x -= img->w / 2;
	while (x < 0)
	{
		x++;
		x_img++;
	}
	while (x < d->def.x && x_img < img->w)
	{
		if (d->z_buf[x] > dist){
			print_sprite_col(d, img, x_img, x);
			}
		x_img++;
		x++;
	}
}

void		print_sprite(t_cub3d *d)
{
	t_sprite	*cur;
	int			x;
	t_img		*img;
	double		dist_to_screen;
	double		proj_h;
	double		proj_w;
	double		sprite_h;

	sprite_h = 1;
	cur = d->sprite;
	while(cur)
	{
		x = (int)find_sprite_col(cur, d);
		dist_to_screen = (d->def.x / 2) / tan(d->fov / 2);
		proj_h = ((sprite_h / cur->dist) * dist_to_screen);
		proj_w = d->text_sprite.w * (proj_h / d->text_sprite.h);
		img = resize_image(d, &d->mlx, &d->text_sprite, proj_w, proj_h);
		print_sprite_to_screen(d, img, x, cur->dist);
		mlx_destroy_image(d->mlx.ptr, img->img);
		free(img);
		cur = cur->next;
	}
}