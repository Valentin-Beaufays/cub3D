#include <string.h>
#include <errno.h>
#include "struct.h"
#include "utils.h"
#include "error.h"

int	out_of_bound_sprite_col(t_sprite *s, t_cub3d *d, int dir)
{
	double	tmp_angle;
	int		pos;

	pos = 0;
	if (dir == -1)
	{
		tmp_angle = d->angle_buf[0];
		while (is_greater_angle(s->angle, tmp_angle))
		{
			tmp_angle = round_rad(tmp_angle + d->step_rad);
			pos--;
		}
	}
	else if (dir == 1)
	{
		tmp_angle = d->angle_buf[(int)d->def.x - 1];
		pos = d->def.x - 1;
		while (is_greater_angle(tmp_angle, s->angle))
		{
			tmp_angle = round_rad(tmp_angle - d->step_rad);
			pos++;
		}
	}
	return (pos);
}

double	find_sprite_col(t_sprite *s, t_cub3d *d)
{
	int pos;

	if (is_greater_angle(s->angle, d->angle_buf[0]))
		pos = out_of_bound_sprite_col(s, d, -1);
	else if (is_greater_angle(d->angle_buf[(int)d->def.x - 1], s->angle))
		pos = out_of_bound_sprite_col(s, d, 1);
	else
	{
		pos = 0;
		while (s->angle < d->angle_buf[pos])
			pos++;
	}
	return (pos);
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
