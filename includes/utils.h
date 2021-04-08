#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

int		rgb_to_int(int r, int g, int b);
int		check_path(char *path, char *ext);
double	deg2rad(double deg);
double	rad2deg(double rad);
double	round_rad(double rad);
void	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		mlx_setup(t_mlx *m, t_cub3d *d);
double	ft_abs(double val);

#endif
