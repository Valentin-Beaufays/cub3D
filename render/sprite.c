#include <string.h>
#include <errno.h>
#include "struct.h"
#include "utils.h"
#include "error.h"

int	out_of_bound_sprite_col(t_sprite *s, t_cub3d *d, int dir)
{
	double	tmp_angle;
	int		col;

	col = 0;
	if (dir == -1)
	{
		tmp_angle = d->angle_buf[0];
		while (is_greater_angle(s->angle, tmp_angle))
		{
			tmp_angle = round_rad(tmp_angle + d->step_rad);
			col--;
		}
	}
	else if (dir == 1)
	{
		tmp_angle = d->angle_buf[(int)d->def.x - 1];
		col = d->def.x - 1;
		while (is_greater_angle(tmp_angle, s->angle))
		{
			tmp_angle = round_rad(tmp_angle - d->step_rad);
			col++;
		}
	}
	return (col);
}

double	find_sprite_col(t_sprite *s, t_cub3d *d)
{
	int col;

	if (is_greater_angle(s->angle, d->angle_buf[0]))
		col = out_of_bound_sprite_col(s, d, -1);
	else if (is_greater_angle(d->angle_buf[(int)d->def.x - 1], s->angle))
		col = out_of_bound_sprite_col(s, d, 1);
	else
	{
		col = 0;
		while (s->angle < d->angle_buf[col])
			col++;
	}
	return (col);
}

void	sprite_found(t_cub3d *data, double x, double y)
{
	t_sprite	*new;
	if (is_new_sprite(data->sprite, x, y))
	{
		if (!(new = create_sprite(data->pos.x, data->pos.y, x, y)))
			free_data_err(strerror(errno), NULL, data);
		if (data->sprite)
			data->sprite = add_sprite(data->sprite, new);
		else
			data->sprite = new;
	}
}
