#include <mlx.h>

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    int x;
    int y;
    int i;
    int j;
    int color;

    i = 0;
    j = 0;
    x = 1920;
    y= 1080;
    color = 16777215;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, x, y, "cub3D");
   while (i < x)
    {
        while (j < y)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, i, j, mlx_get_color_value(mlx_ptr, color));
            j++;
        }  
        j = 0; 
        i++; 
    }
    mlx_loop(mlx_ptr);
    return (0);
}