#include <math.h>
#include "struct.h"
#include "utils.h"

t_text	*get_wall_text(t_cub3d *data, int text_dir)
{
	if (text_dir == 0)
		return (&data->text_e);
	else if (text_dir == 1)
		return (&data->text_s);
	else if (text_dir == 2)
		return (&data->text_w);
	else if (text_dir == 3)
		return (&data->text_n);
	else
		return (NULL);
}

int		get_text_col(t_text *text, double new_w, double intersect)
{
	double	ratio_w;
	double		col;
	double	col_size;

	col = 0;
	intersect = intersect - (int)intersect;
	ratio_w = (double)text->w / new_w;
	col_size = 1/new_w;
	while (intersect >= col_size * (double)(col + 1))
		col++;
	return ((int)(col * ratio_w));
}

void	print_text(t_cub3d *data, t_text *text, double proj_size, int x, int text_x)
{
	int		y;
	int		start;
	double	text_y;
	double	ratio_h;
	int		color;

	y = 0;
	start = (int)((data->def.y / 2) - (proj_size / 2));
	text_y = 0;
	ratio_h = (double)text->h / proj_size;
	while (start < 0)
	{
		text_y += 1;
		start++;
	}
	while (y < start)
	{
		ft_mlx_pixel_put(&data->mlx, &data->mlx.frame, x, y, data->color_ceil);
		y++;
	}
	while ((double)y < proj_size && y < (int)data->def.y)
	{
		color = ft_mlx_pixel_get(&text->img, text_x, (int)(text_y * ratio_h));
		ft_mlx_pixel_put(&data->mlx, &data->mlx.frame, x, y, color);
		text_y +=1;
		y++;
	}
	while (y < (int)data->def.y)
	{
		ft_mlx_pixel_put(&data->mlx, &data->mlx.frame, x, y, data->color_floor);
		y++;
	}
}

void    print_column(t_ray *r, t_cub3d *d, int x)
{
	t_text	*wall_text;
	int		text_col;
	double	dist_to_wall;
	double	dist_to_screen;
	double	proj_size;

	dist_to_wall = get_dist(&d->pos, &r->i) * cos(r->angle - d->angle);
	dist_to_screen = (d->def.x / 2) / tan(d->fov / 2);//TO_DO: store in t_cub3d
	proj_size = (1 / dist_to_wall) * dist_to_screen;
	if (x == 0)
		printf("%f\n",proj_size);
	wall_text = get_wall_text(d, r->text_dir);
	text_col = get_text_col(wall_text, proj_size, r->i.x);
	print_text(d, wall_text, proj_size, x, text_col);
}