#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

void	free_data(t_cub3d *data)
{
	free_map(&data->map);
	free_text(&data->mlx, &data->text_sprite);
	free_text(&data->mlx, &data->text_n);
	free_text(&data->mlx, &data->text_s);
	free_text(&data->mlx, &data->text_w);
	free_text(&data->mlx, &data->text_e);
	free_mlx(&data->mlx);
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