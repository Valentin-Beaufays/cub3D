#include <stddef.h>
#include <stdlib.h>
#include "struct.h"

void	free_map(t_map *map)
{
	size_t i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	free_temp(t_temp *temp)
{
	if (temp->north)
		free(temp->north);
	if (temp->south)
		free(temp->south);
	if (temp->west)
		free(temp->west);
	if (temp->east)
		free(temp->east);
	if (temp->sprite)
		free(temp->sprite);
}
