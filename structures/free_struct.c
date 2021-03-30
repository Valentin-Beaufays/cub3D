#include "../includes/cub3d.h"

void free_temp(t_temp *temp)
{
    size_t i;

    i = 0;
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
    {
        while (temp->map[i])
        {
            free(temp->map[i]);
            i++;
        }
        free(temp->map);
    }
}