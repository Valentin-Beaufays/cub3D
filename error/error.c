#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void	ft_error(char *error)
{
	printf("Error: %s\n", error);
	exit(-1);
}

void	free_tmp_err(char *error, t_temp *temp, int select)
{
	if ((select == 1 || select == 3) && temp->line)
		free(temp->line);
	if ((select == 2 || select == 3) && temp->trim)
		free(temp->trim);
	free_temp(temp);
	ft_error(error);
}

void	free_data_err(char *error, t_temp *temp, t_cub3d *data)
{
	free_data(data);
	free_temp(temp);
	free_map(&temp->map);
	ft_error(error);
}
