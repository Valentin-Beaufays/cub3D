#include "mlx.h"
#include "struct.h"

void	ft_mlx_pixel_put(t_mlx *mlx, t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->length + x * (img->bpp / 8));
	*(unsigned int*)dst = mlx_get_color_value(mlx->ptr, color);
}



int		ft_mlx_pixel_get(t_img *img, int x, int y)
{
	int ret;

	ret = *(int*)(img->addr + (y * img->length + x * (img->bpp / 8)));
	return (ret);
}