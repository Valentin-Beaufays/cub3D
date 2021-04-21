#ifndef SPRITE_H
# define SPRITE_H

# include "struct.h"

void	sprite_found(t_cub3d *data, double x, double y);
double	find_sprite_col(t_sprite *s, t_cub3d *d);
void	print_sprite(t_cub3d *d);

#endif
