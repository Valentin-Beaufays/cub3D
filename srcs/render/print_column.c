#include <math.h>
#include "struct.h"
#include "utils.h"

void    print_column(t_ray *ray, t_cub3d *data, int x)
{
	double  wall_h;
	double  projWall_h;
	double  distToWall;
	double  distToScreen;
	int     start;
	int     end;
	int     y;
	int     wallColor;

	y = 0;
	wall_h = 1;
	distToWall = sqrt(pow(data->pos.x - ray->i.x, 2) + pow(data->pos.y - ray->i.y, 2)) * cos(ray->angle - data->angle);
	data->z_buf[x] = distToWall;
	distToScreen = (data->def.x / 2) / tan(data->fov / 2);
	projWall_h = ((wall_h / distToWall) * distToScreen) ;
	if (projWall_h > data->def.y)
		projWall_h = data->def.y;
	else if (projWall_h < 0)
		projWall_h = 0;
	start = (data->def.y / 2) - projWall_h / 2;
	end = start + projWall_h;
	wallColor = rgb_to_int(0,255,0);

	if (ray->text_dir == 1 || ray->text_dir == 3)
		wallColor = rgb_to_int(255,0,0);

	while (y < start)
	{
		ft_mlx_pixel_put(&data->mlx, &data->mlx.frame, x, y, data->color_ceil);
		y++;
	}
	while (y < end && y < data->def.y)
	{
		ft_mlx_pixel_put(&data->mlx, &data->mlx.frame, x, y, wallColor);
		y++;
	}
	while (y < data->def.y)
	{
		ft_mlx_pixel_put(&data->mlx, &data->mlx.frame, x, y, data->color_floor);
		y++;
	}
}