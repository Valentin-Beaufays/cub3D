#include <stddef.h>
#include <unistd.h>
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

void	free_sprite(t_sprite *sprite)
{
	t_sprite *next;

	while (sprite)
	{
		next = sprite->next;
		free(sprite);
		sprite = next;
	}
}

void	free_data(t_cub3d *data)
{
	free_map(&data->map);
	if (data->text_sprite)
		free(data->text_sprite);
	if (data->text_n)
		free(data->text_n);
	if (data->text_s)
		free(data->text_s);
	if (data->text_e)
		free(data->text_e);
	if (data->text_w)
		free(data->text_w);
	if (data->z_buf)
		free(data->z_buf);
	free_sprite(data->sprite);
	free(data);
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
	if (temp->fd < 0)
		close(temp->fd);
}
