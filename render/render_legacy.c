#include "../libft/libft.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <math.h>
#include <mlx.h>

#define screenW 480
#define screenH 480
#define mapWidth 13
#define mapHeight 3
#define SIZE 64

char Map[mapHeight][mapWidth]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void init_ray(t_ray *ray)
{
	ray->up = 0;
	ray->left = 0;
	ray->h_intersect.x = -1;
	ray->h_intersect.y = -1;
	ray->v_intersect.x = -1;
	ray->v_intersect.y = -1;
	ray->h_intersect.y = -1;
	ray->intersect.x = -1;
	ray->intersect.y = -1;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->ray_angle = 0;
}

void copy_map(t_map *map)
{
	int x;

	while (x < mapWidth)
	{
		ft_memcpy(map->map[x], Map[x], mapHeight);
		x++;
	}
}

void getRayDir(double angle, int *up, int *left)
{
	if (angle > 0 && angle < M_PI)
		*up = 1;
	else if (angle > M_PI)
		*up = -1;
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		*left = 1;
	else if (angle < M_PI / 2 || angle > 3 * M_PI / 2)
		*left = -1;
}

int	check_hit(t_ray *ray, t_cub3d *data)
{
	if (ray->intersect.x >= 0 && ray->intersect.y >= 0 && ray->intersect.x < data->map.w && ray->intersect.y < data->map.h)
	{
		int up;
		int left;

		up = 0;
		left = 0;
		if (ray->up == 1)
			up = 1;
		if (ray->left == 1)
			left = 1;
		if (data->map.map[(int)ray->intersect.x - left][(int)ray->intersect.y - up] == 1)
			return (1);
		else
			return (0);
	}
	return (-1);
}

int check_hit_loop(t_ray *ray, t_cub3d *data)
{
	int	hit;

	hit = check_hit(ray, data);
	while (!hit)
	{
		ray->intersect.x += ray->step_x;
		ray->intersect.x += ray->step_y;
		hit = check_hit(ray, data);
	}
	return (hit);
}

int	find_h_intersection(t_ray *ray, t_cub3d *data)
{
	if (ray->up != 0)
	{
		if (ray->up == 1)
		{
			ray->intersect.y = floor(data->pos.x);
			ray->step_y = -1;
		}
		else
		{
			ray->intersect.y = floor(data->pos.y) + 1;
			ray->step_y = 1;
		}
		if (ray->left != 0)
		{
			ray->intersect.x = data->pos.x + (data->pos.y - ray->intersect.y) / tan(ray->ray_angle);
			ray->step_x = (1 / tan(ray->ray_angle)) * ray->up;
		}
		else
		{
			ray->intersect.x = data->pos.x;
			ray->step_x = 0;
		}
		return (check_hit_loop(ray, data));
	}
	return (-1);
}
int	find_v_intersection(t_ray *ray, t_cub3d *data)
{
	if (ray->left != 0)
	{
		if (ray->left == 1)
		{
			ray->intersect.x = floor(data->pos.x);
			ray->step_x = -1;
		}
		else
		{
			ray->intersect.x = floor(data->pos.x) + 1;
			ray->step_x = 1;
		}
		ray->intersect.y = data->pos.y + (data->pos.x - ray->intersect.x) * tan(ray->ray_angle);
		ray->step_y = tan(ray->ray_angle) * ray->left;
		return (check_hit_loop(ray, data));
	}
	return (-1);
}

void find_nearest_intersection(t_ray *ray, t_cub3d *data)
{
	double distH;
	double distV;
	if (ray->h_intersect.x != -1)
	{
		distH = ABS(data->pos.x - ray->h_intersect.x) + ABS(data->pos.y - ray->h_intersect.y);
		distV = ABS(data->pos.x - ray->v_intersect.y) + ABS(data->pos.y - ray->v_intersect.y);
		if (ray->v_intersect.x == -1 || distH < distV)
		{
			ray->intersect.x = ray->h_intersect.x;
			ray->intersect.y = ray->h_intersect.y;
		}
	}
}

void find_intersection(t_ray *ray, t_cub3d *data)
{
		getRayDir(ray->ray_angle, &ray->up, &ray->left);
		if (find_h_intersection(ray, data) == 1)
		{
			ray->h_intersect.x = ray->intersect.x;
			ray->h_intersect.y = ray->intersect.y;
		}
		if (find_v_intersection(ray, data) == 1)
		{
			ray->v_intersect.x = ray->intersect.x;
			ray->v_intersect.y = ray->intersect.y;
		}
		find_nearest_intersection(ray, data);
		//printf("h: (%f;%f), v (%f;%f), (%f;%f)\n", ray->intersect.x, ray->intersect.y);
}

void            ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bpp / 8));
    *(unsigned int*)dst = mlx_get_color_value(mlx->ptr, color);
}

int	rgb_to_int(int r, int g, int b)
{
	return (((256*256) * r) + (256 * g) + b);
}
void render_column(t_ray *ray, t_cub3d *data, int x)
{
	double distWall;
	double perceived;
	int y;
	int start;
	int end;

	distWall = sqrt((pow((data->pos.x - ray->intersect.x) * 64, 2) + pow((data->pos.y - ray->intersect.y) * 64, 2)));
	perceived = (data->distCam * data->wallHeight) / (distWall * 64);
	start = (data->def.y / 2) - (perceived / 2);
	end = (data->def.y / 2) + (perceived / 2);
	y = 0;
	//printf("start : %d , end : %d\n", start, end);
	//printf("%f %f %d\n", distWall, perceived, y);

	while (y < start)
	{
		//afficher ciel

		ft_mlx_pixel_put(&data->mlx, x, y, data->color_ceil);
		//printf("x : %d y : %d  --- CIEL \n", x, y);
		y++;
	}

	while (y >= start && y < end )
	{
		//afficher mur
		ft_mlx_pixel_put(&data->mlx, x, y, rgb_to_int(255,255,255));
		//printf("x : %d y : %d  --- MUR\n", x, y);
		y++;
	}
	while(y >= end && y < data->def.y)
	{
		//afficher sol
		ft_mlx_pixel_put(&data->mlx, x, y, data->color_floor);
		//printf("x : %d y : %d  --- SOL\n", x, y);

		y++;
	}
}

void	render(t_cub3d *data)
{
	t_ray	ray;
	int		x;
	init_ray(&ray);
	ray.ray_angle = data->angle + (data->fov / 2); //check if > 2 * M_PI
	x = 0;
	while(x <1)
	{
		find_intersection(&ray, data);

		ray.ray_angle -= data->step_rad;
		render_column(&ray, data , x);
		x++;
	}
}

int	main()
{
	t_cub3d data;

	data.def.x = screenW;
	data.def.y = screenH;
	data.pos.x = 1.5, data.pos.y = 1.5;  //x and y start position
	data.angle = 0 * M_PI / 180;
	data.fov = 60 * M_PI / 180;
	data.step_rad = data.fov / data.def.x;
	data.distCam = (data.def.x / 2) / tan(data.fov / 2);
	data.wallHeight = 64;
	data.color_ceil = rgb_to_int(0, 191, 255);
	data.color_floor = rgb_to_int(204, 102, 0);
	data.map.h = 4;
	data.map.w = 4;
	copy_map(&data.map);
	//init mlx
	data.mlx.ptr = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.ptr, data.def.x, data.def.y, "raycaster");
	data.mlx.img = mlx_new_image(data.mlx.ptr, data.def.x, data.def.y);
	data.mlx.addr = mlx_get_data_addr(data.mlx.img, &data.mlx.bpp, &data.mlx.line_length, &data.mlx.endian);
	//mlx_key_hook(mlx.win, key_hook, &mlx);
	//mlx_loop_hook(mlx.mlx, render, &mlx);
	render(&data);
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.mlx.img, 0, 0);
	mlx_loop(data.mlx.ptr);
	return(0);
}
