#ifndef RENDER_H
# define RENDER_H

# include "struct.h"

int		render(t_cub3d *data);
int		check_h_hit(t_cub3d *data, t_ray *ray, t_map *map);
int		check_v_hit(t_cub3d *data, t_ray *ray, t_map *map);
int		check_hit_loop(t_ray *ray, t_cub3d *data,
						int (*f)(t_cub3d *data, t_ray *ray, t_map *map));
void	find_intersection(t_ray *ray, t_cub3d *data);
void	print_column(t_ray *ray, t_cub3d *data, int x);
int		rgb_to_int(int r, int g, int b);

#endif
