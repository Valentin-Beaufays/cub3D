#ifndef RENDER_H
# define RENDER_H

# include "struct.h"

# define screenW 480
# define screenH 480
# define mapWidth 13
# define mapHeight 3
# define SIZE 64

double  deg2rad(double deg);
double  rad2deg(double rad);
double  round_rad(double rad);
void    getRayDir(double angle, int *up, int *left);
int	    check_h_hit(t_ray *ray, t_cub3d *data);
int	    check_v_hit(t_ray *ray, t_cub3d *data);
int     check_hit_loop(t_ray *ray, t_cub3d *data, int (*c_h)(t_ray *ray, t_cub3d *data));
int     find_h_intersect(t_ray *ray, t_cub3d *data);
int	    find_v_intersection(t_ray *ray, t_cub3d *data);
void    find_nearest_intersection(t_ray *ray, t_cub3d *data);
void    find_intersection(t_ray *ray, t_cub3d *data);

#endif