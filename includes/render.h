#ifndef RENDER_H
# define RENDER_H

# include "struct.h"

double	deg2rad(double deg);
double	rad2deg(double rad);
double	round_rad(double rad);
int		render(t_cub3d *data);
int		check_h_hit(t_ray *ray, t_cub3d *data);
int		check_v_hit(t_ray *ray, t_cub3d *data);
int		check_hit_loop(t_ray *ray, t_cub3d *data,
						int (*c_h)(t_ray *ray, t_cub3d *data));
void	find_intersection(t_ray *ray, t_cub3d *data);
void	print_column(t_ray *ray, t_cub3d *data, int x);
int		rgb_to_int(int r, int g, int b);

#endif
