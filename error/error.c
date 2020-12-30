#include "../includes/cub3d.h"

void    ft_error(char *error)
{
    printf("Error: %s\n", error);
    exit(-1);
}

void free_tmp_err(char *error, t_temp *temp, int select)
{
    if ((select == 1 || select == 3) && temp->line)
        free(temp->line);
    if ((select == 2 || select == 3) && temp->trim)
        free(temp->trim);
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
    if (temp->map)
        free(temp->map);
    ft_error(error);
}