#include <mlx.h>
#include <stddef.h>

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	int		x;
	int		y;
	int		i;
	int		j;
	int		color;
	char	*dst;

	i = 0;
	j = 0;
	x = 1280;
	y= 720;
	color = 16777215;
	dst = NULL;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, x, y, "cub3D");
	img.img = mlx_new_image(mlx_ptr, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	while (i < x)
	{
		while (j < y)
		{
			dst = img.addr + (j * img.line_length + i * (img.bpp/8));
			*(unsigned int*)dst = color;
			j++;
		}
		j = 0; 
		i++; 
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
