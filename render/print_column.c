#include "../includes/render.h"
#include <math.h>
#include <stdio.h>
#include <mlx.h>

void    ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx->addr + (y * mlx->length + x * (mlx->bpp / 8));
    *(unsigned int*)dst = mlx_get_color_value(mlx->ptr, color);
}

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
    distToWall = sqrt(pow(data->pos.x - ray->intersect.x, 2) + pow(data->pos.y - ray->intersect.y, 2)) * cos(ray->rayAngle - data->angle);
    distToScreen = (data->def.x / 2) / tan(data->fov / 2);
    projWall_h = ((wall_h / distToWall) * distToScreen) ;
    if (projWall_h > data->def.y)
        projWall_h = data->def.y;
    else if (projWall_h < 0)
        projWall_h = 0;
    //printf("wall_h: %f, distToWall: %f, distToScreen:%f, projWall_h: %f", wall_h, distToWall, distToScreen, projWall_h);
    start = (data->def.y / 2) - projWall_h / 2;
    end = start + projWall_h;
    wallColor = rgb_to_int(0,255,0);

    if (ray->text_dir == 1 || ray->text_dir == 3)
        wallColor = rgb_to_int(255,0,0);

    while (y < start)
    {
        ft_mlx_pixel_put(&data->mlx, x, y, data->color_ceil);
        y++;
    }
    while (y < end && y < data->def.y)
    {
        ft_mlx_pixel_put(&data->mlx, x, y, wallColor);
        y++;
    }
    while (y < data->def.y)
    {
        ft_mlx_pixel_put(&data->mlx, x, y, data->color_floor);
        y++;
    }
}