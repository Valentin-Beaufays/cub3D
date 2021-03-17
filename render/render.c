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
	double		hX;
	double		hY;
	double		vX;
	double		vY;
	double		stepX;
	double		stepY;
	double		rayAngle;
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

void	render(t_mlx *mlx)
{
	t_ray ray;
	int x = 0;
	int hit = 0;
	int up = 0;
	int left = 0;
	ray.rayAngle = mlx->angle + (mlx->fov / 2); //check if > 2 * M_PI
	while(x < 1)
	{
		getRayDir(ray.rayAngle, &up, &left);
		//horizontal intersection
		if (up != 0)
		{
			if (up == 1)
			{
				ray.hY = floor(mlx->posY);
				ray.stepY = -1;
			}
			else
			{
				ray.hY = floor(mlx->posY) + 1;
				ray.stepY = 1;
			}

			if (left != 0)
			{
				ray.hX = mlx->posX + (mlx->posY - ray.hY) / tan(ray.rayAngle);
				ray.stepX = (1 / tan(ray.rayAngle)) * up;
			}
			else
			{
				ray.hX = mlx->posX;
				ray.stepX = 0;
			}
			//TO_DO: hit = check hit
			while (!hit)
			{
				ray.hX += ray.stepX;
				ray.hY += ray.stepY;
				//TO_DO: hit = check hit
			}
		}
		hit = 0;
		//TO_DO: vertical intersection
		if (left != 0)
		{
			if (left == 1)
			{
				ray.vX = floor(mlx->posX);
				ray.stepX = -1;
			}
			else
			{
				ray.vX = floor(mlx->posX) + 1;
				ray.stepX = 1;
			}
			ray.vY = mlx->posY + (mlx->posX - ray.vX) * tan(ray.rayAngle);
			ray.stepY = tan(ray.rayAngle) * left;
			//TO_DO: hit = check hit
			while (!hit)
			{
				ray.vX += ray.stepX;
				ray.vY += ray.stepY;
				//TO_DO: hit = check hit
			}
		}
		//TO_DO: find nearest intersection
		printf("(%f;%f), sX: %f, sY: %f, alpha: %f, %d\n", ray.hX, ray.hY, ray.stepX, ray.stepY, ray.rayAngle, up);
		x++;
	}
}

int	main()
{
	t_mlx	mlx;
	mlx.posX = 1.5, mlx.posY = 1.5;  //x and y start position
	mlx.angle = 15 * M_PI / 180;
	mlx.fov = 60 * M_PI / 180;
	mlx.stepRad = (double)screenW / mlx.fov;

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
