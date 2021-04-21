#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

int				rgb_to_int(int r, int g, int b);
int				check_path(char *path, char *ext);
double			deg2rad(double deg);
double			rad2deg(double rad);
int				is_greater_angle(double base, double cmp);
double			round_rad(double rad);
void			ft_mlx_pixel_put(t_mlx *mlx, t_img *img, int *xy, int col);
int				ft_mlx_pixel_get(t_img *img, int x, int y);
int				mlx_setup(t_mlx *m, t_cub3d *d);
double			ft_abs(double val);
int				is_new_sprite(t_sprite *sprite, double x, double y);
t_sprite		*add_sprite(t_sprite *s, t_sprite *new);
t_sprite		*create_sprite(double pos_x, double pos_y,
								double new_x, double new_y);
t_img			*resize_image(t_cub3d *d, t_text *t, int w, int h);
double			get_dist(t_point *f, t_point *t);
unsigned char	get_red(int color);
unsigned char	get_green(int color);
unsigned char	get_blue(int color);

#endif
