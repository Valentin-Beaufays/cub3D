#include "../cub3d.h"

void    ft_error(char *error)
{
    printf("Error: %s", error);
    exit(-1);
}

void    free_temp_error(char *error, t_temp *temp)
{
    free(temp->line);
    free(temp->trim);
    free(temp->x);
    free(temp->y);
    free(temp->north);
    free(temp->south);
    free(temp->west);
    free(temp->east);
    free(temp->map);
    ft_error(error);
}