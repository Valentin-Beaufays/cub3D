
#include <mlx.h>
#include <math.h>
#include "../libft/libft.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
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
  double posX;
  double posY;
  double dirX;
  double dirY;
  double planeX;
  double planeY;
  double deltaDistX;
  double deltaDistY;
  double rayDirX;
  double rayDirY;
  double cameraX;

}				t_mlx;

void caster(t_mlx *mlx)
{
      mlx->cameraX = 2 * 0 / 640.0 - 1; //x-coordinate in camera space
      mlx->rayDirX = mlx->dirX + mlx->planeX * mlx->cameraX;
      mlx->rayDirY = mlx->dirY + mlx->planeY * mlx->cameraX;
      mlx->deltaDistX = (mlx->rayDirY == 0) ? 0 : ((mlx->rayDirX == 0) ? 1 : ABS(1 / mlx->rayDirX));
      mlx->deltaDistY = (mlx->rayDirX == 0) ? 0 : ((mlx->rayDirY == 0) ? 1 : ABS(1 / mlx->rayDirY));
      //which box of the map we're in
      int mapX = (int)(mlx->posX);
      int mapY = (int)mlx->posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = ABS(1 / mlx->rayDirX);
      double deltaDistY = ABS(1 / mlx->rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?


}

int main()
{
  t_mlx	mlx;
  mlx.posX = 22, mlx.posY = 12;  //x and y start position
  mlx.dirX = -1, mlx.dirY = 0; //initial direction vector
  mlx.planeX = 0, mlx.planeY = 0.66; //the 2d raycaster version of camera plane

  double time = 0; //time of current frame
  double oldTime = 0; //time of previous fr
  double test = 1.25;

	//init mlx
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "raycaster");
  mlx.img = mlx_new_image(mlx.mlx, screenWidth, screenHeight);
  printf("%i", (int)test);
  //caster(&mlx);
	return(0);
}