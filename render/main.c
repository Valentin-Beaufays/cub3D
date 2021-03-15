
#include <mlx.h>
#include <math.h>
#include "../libft/libft.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int Map[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct	mlx
{
	void	*mlx;
	void	*win;
	void	*img;
  void  *addr;
  int   bpp;
  int   line_length;
  int   endian;
  double posX;
  double posY;
  double dirX;
  double dirY;
  double planeX;
  double planeY;
}				t_mlx;

typedef struct  s_ray
{
  int mapX;
  int mapY;
  double rayDirX;
  double rayDirY;
  double cameraX;
  double sideDistX;
  double sideDistY;
  double deltaDistX;
  double deltaDistY;
  double perpWallDist; //for calculate dist to intersection 
  int stepX;
  int stepY;
  int hit;
  int side;
  int drawStart;
  int drawEnd;
  int lineHeight;
}               t_ray;

void ft_mlx_put_pixel(t_mlx *mlx, int x, int y, int color)
{
  char *dst;

  dst = mlx->addr + (y * mlx->line_length + x * (mlx->bpp / 8));
  *(unsigned int*)dst = mlx_get_color_value(mlx->mlx, color); 
}

void caster(t_mlx *mlx)
{

    t_ray ray;
    int x;

    x = 0;
    while (x < screenWidth)
    {
      //loop for each pixel column
	    ray.cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
	    ray.rayDirX = mlx->dirX + mlx->planeX * ray.cameraX;
	    ray.rayDirY = mlx->dirY + mlx->planeY * ray.cameraX;

	    //which box of the map we're in
	    ray.mapX = (int)mlx->posX;
	    ray.mapY = (int)mlx->posY;

	     //length of ray from one x or y-side to next x or y-side
	    ray.deltaDistX = ABS(1 / ray.rayDirX);
	    ray.deltaDistY = ABS(1 / ray.rayDirY);

      //initial SideDist

      if (ray.rayDirX < 0)
      {
        ray.stepX = -1;
        ray.sideDistX = (mlx->posX - ray.mapX) * ray.deltaDistX;
      }
      else
      {
        ray.stepX = 1;
        ray.sideDistX = ((ray.mapX + 1.0) - mlx->posX) * ray.deltaDistX;
      }
      if (ray.rayDirY < 0)
      {
        ray.stepY = -1;
        ray.sideDistY = (mlx->posY - ray.mapY) * ray.deltaDistY;
      }
      else
      {
        ray.stepY = 1;
        ray.sideDistY = ((ray.mapY + 1.0) - mlx->posY) * ray.deltaDistY;
      }

      //DDA
      while (ray.hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (ray.sideDistX < ray.sideDistY)
        {
          ray.sideDistX += ray.deltaDistX;
          ray.mapX += ray.stepX;
          ray.side = 0;
        }
        else
        {
          ray.sideDistY += ray.deltaDistY;
          ray.mapY += ray.stepY;
          ray.side = 1;
        }
        //Check if ray has hit a wall
        if (Map[ray.mapX][ray.mapY] > 0) 
          ray.hit = 1;
      }
      // calculate dist to wall
      if (ray.side == 0) 
        ray.perpWallDist = (ray.mapX - mlx->posX + (1 - ray.stepX) / 2) / ray.rayDirX;
      else           
        ray.perpWallDist = (ray.mapY - mlx->posY + (1 - ray.stepY) / 2) / ray.rayDirY;

      //trace
      int y;

      y = 0;
      ray.lineHeight = (int)(screenHeight / ray.perpWallDist);
      ray.drawStart = (int)(((screenHeight - ray.lineHeight) / 2) + 1);
      ray.drawEnd = ray.drawStart + ray.lineHeight;
      while (y < screenHeight)
      {
        if (y < ray.drawStart)
          ft_mlx_put_pixel(mlx, x, y, 0);
        else if (y < ray.drawEnd)
          ft_mlx_put_pixel(mlx, x, y, 16777215);
        else
          ft_mlx_put_pixel(mlx, x, y, 0);
        y++;
      }
    x++;
    }
}

void render(t_mlx *mlx)
{
  caster(mlx);
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void key_hook(int key, t_mlx *mlx)
{
  //rotate
  double rotSpeed = 0.5;
  double oldDirX = mlx->dirX;
  mlx->dirX = mlx->dirX * cos(rotSpeed * -1) - mlx->dirY * sin(rotSpeed * -1);
  mlx->dirY = oldDirX * sin(rotSpeed * -1) + mlx->dirY * cos(rotSpeed * -1);
  double oldPlaneX = mlx->planeX;
  mlx->planeX = mlx->planeX * cos(rotSpeed * -1) - mlx->planeY * sin(rotSpeed * -1);
  mlx->planeY = oldPlaneX * sin(rotSpeed * -1) + mlx->planeY * cos(rotSpeed * -1);
  render(mlx);
}

int main()
{
  t_mlx	mlx;
  mlx.posX = 4, mlx.posY = 6;  //x and y start position
  mlx.dirX = -1, mlx.dirY = 0; //initial direction vector
  mlx.planeX = 0, mlx.planeY = 0.66; //the 2d raycaster version of camera plane

  double time = 0; //time of current frame
  double oldTime = 0; //time of previous fr
  double test = 1.25;

	//init mlx
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "raycaster");
  mlx.img = mlx_new_image(mlx.mlx, screenWidth, screenHeight);
  mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_length, &mlx.endian);
  mlx_key_hook(mlx.win, key_hook, &mlx);
  mlx_loop_hook(mlx.mlx, render, &mlx);
  mlx_loop(mlx.mlx);
	return(0);
}