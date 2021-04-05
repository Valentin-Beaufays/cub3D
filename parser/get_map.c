#include <stddef.h>
#include "parser.h"
#include "struct.h"
#include "error.h"

static void	map_to_data(t_map *dst, t_map *src)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (src->map[y])
	{
		x = 0;
		while (src->map[y][x])
		{
			if (src->map[y][x] == ' ')
				src->map[y][x] = 1;
			else
				src->map[y][x] -= 48;
			x++;
		}
		y++;
	}
	dst->h = src->h;
	dst->w = src->w;
	dst->map = src->map;
}

void		get_map(t_temp *temp, t_cub3d *data)
{
	int	find_pos;

	if (!(find_pos = get_pos(temp->map.map, data)))
		free_data_err("no start position was found", temp, data);
	else if (find_pos > 1)
		free_data_err("too many start positions were found", temp, data);
	check_valid(temp, data);
	map_to_data(&data->map, &temp->map);
}
