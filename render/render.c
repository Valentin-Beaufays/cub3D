#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <mlx.h>

#define screenW 640
#define screenH 480
#define mapWidth 4
#define mapHeight 4
#define SIZE 64

typedef struct	mlx
{
	void		*mlx;
	void		*win;
	void		*img;
  	void		*addr;
  	int			bpp;
  	int			line_length;
  	int			endian;
  	double		posX;
  	double		posY;
	double		angle;
	double		stepRad;
	double		fov;
}				t_mlx;

typedef struct  s_ray
{
	int			up = 0;
	int			left = 0;
	double		hX = -1;
	double		hY = -1;
	double		vX = -1;
	double		vY = -1;
	double		x = -1; 
	double		y = -1; 
	double		stepX;
	double		stepY;
	double		rayAngle = mlx->angle + (mlx->fov / 2); //check if > 2 * M_PI;
}               t_ray;

int Map[mapWidth][mapHeight]=
{
  {1,1,1,1},
  {1,0,0,1},
  {1,0,0,1},
  {1,1,1,1}
};

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

int	check_hit(t_ray *ray/*, char **map*/)
{
	if (ray->x >= 0 && ray->y >= 0 && ray->x < mapWidth && ray->y < mapHeight)
	{
		int up;
		int left;

		up = 0;
		left = 0;
		if (ray->up == 1)
			up = 1;
		if (ray->left == 1)
			left = 1;
		if (Map[(int)ray->x - left][(int)ray->y - up] == 1)
			return (1);
		else
			return (0);
	}
	return (-1);
}

int check_hit_loop(t_ray *ray)
{
	int	hit;

	hit = check_hit(ray);
	while (!hit)
	{
		ray->x += ray->stepX;
		ray->x += ray->stepY;
		hit = check_hit(ray);
	}
	return (hit);
}

int	find_h_intersection(t_ray *ray, t_mlx *mlx)
{
	if (ray->up != 0)
	{
		if (ray->up == 1)
		{
			ray->y = floor(mlx->posY);
			ray->stepY = -1;
		}
		else
		{
			ray->y = floor(mlx->posY) + 1;
			ray->stepY = 1;
		}
		if (ray->left != 0)
		{
			ray->x = mlx->posX + (mlx->posY - ray->y) / tan(ray->rayAngle);
			ray->stepX = (1 / tan(ray->rayAngle)) * ray->up;
		}
		else
		{
			ray->x = mlx->posX;
			ray->stepX = 0;
		}
		return (check_hit_loop(ray));
	}
	return (-1);
}
int	find_v_intersection(t_ray *ray, t_mlx *mlx)
{
	if (ray->left != 0)
	{
		if (ray->left == 1)
		{
			ray->x = floor(mlx->posX);
			ray->stepX = -1;
		}
		else
		{
			ray->x = floor(mlx->posX) + 1;
			ray->stepX = 1;
		}
		ray->y = mlx->posY + (mlx->posX - ray->x) * tan(ray->rayAngle);
		ray->stepY = tan(ray->rayAngle) * ray->left;
		return (check_hit_loop(ray));
	}
	return (-1);
}

void find_nearest_intersection(t_ray *ray, t_mlx *mlx)
{
	double distH;
	double distV;
	if (ray->hX != -1)
	{
		distH = ABS(mlx->posX - ray->hX) + ABS(mlx->posY - ray->hY);
		distV = ABS(mlx->posX - ray->vY) + ABS(mlx->posY - ray->vY);
		if (ray->vX == -1 || distH < distV)
		{
			ray->x = ray->hX;
			ray->y = ray->hY;
		}
	}
}

void find_intersection(t_ray *ray, t_mlx *mlx)
{
		getRayDir(ray->rayAngle, ray->up, ray->left);
		if (find_h_intersection(&ray, mlx) == 1)
		{
			ray->hX = ray->x;
			ray->hY = ray->y;
		}
		if (find_v_intersection(&ray, mlx) == 1)
		{
			ray->vX = ray->x;
			ray->vY = ray->y;
		}
		find_nearest_intersection(&ray, mlx);
		printf("(%f;%f)\n", ray->x, ray->y);
		ray->rayAngle -= mlx->stepRad;
}

void	render(t_mlx *mlx)
{
	t_ray	ray;
	int		x;
	//init_ray
	ray.rayAngle = mlx->angle + (mlx->fov / 2); //check if > 2 * M_PI
	int x;

	x = 0;
	while(x < screenW)
	{
		find_intersection(&ray, mlx)
		
		x++;
	{
}

int	main()
{
	t_mlx	mlx;
	mlx.posX = 1.5, mlx.posY = 1.5;  //x and y start position
	mlx.angle = 15 * M_PI / 180;
	mlx.fov = 60 * M_PI / 180;
	mlx.stepRad = mlx.fov / screenW;

	//init mlx
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, screenW, screenH, "raycaster");
	mlx.img = mlx_new_image(mlx.mlx, screenW, screenH);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_length, &mlx.endian);
	//mlx_key_hook(mlx.win, key_hook, &mlx);
	//mlx_loop_hook(mlx.mlx, render, &mlx);
	render(&mlx);
	mlx_loop(mlx.mlx);
	return(0);
}
