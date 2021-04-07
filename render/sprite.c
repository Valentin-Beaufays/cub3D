#include <string.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "error.h"

int			is_new_sprite(t_sprite *sprite, double x, double y)
{
	return (1);
}

t_sprite	*create_sprite(double pos_x, double pos_y, double new_x, double new_y)
{
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return (NULL);
	new->pos.x = new_x;
	new->pos.y = new_y;
	new->dist = sqrt(pow(pos_x - new_x, 2) + pow(pos_y - new_y, 2));
	new->next = NULL;
	return (new);
}

t_sprite	*add_sprite(t_sprite *s, t_sprite *new)
{
	t_sprite	*cur;
	t_sprite	*prev;

	if (!s || !new)
		return (NULL);
	cur = s;
	prev = NULL;
	while (cur)
	{
		if (cur->dist > new->dist)
		{
			prev = cur;
			cur = cur->next;
		}
		else
		{
			new->next = cur;
			if (prev)
				prev->next = new;
			else
				s = new;
			return (s);
		}
	}
	prev->next = new;
	return (s);
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
