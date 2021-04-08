#include <stdlib.h>
#include <math.h>
#include "struct.h"

int			is_new_sprite(t_sprite *sprite, double x, double y)
{
	while (sprite)
	{
		if (sprite->pos.x == x && sprite->pos.y == y)
			return (0);
		sprite = sprite->next;
	}
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
