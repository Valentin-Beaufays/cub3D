#include <string.h>
#include <errno.h>
#include "struct.h"
#include "utils.h"
#include "error.h"

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
