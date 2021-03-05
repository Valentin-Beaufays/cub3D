#include "../includes/cub3d.h"
#include "../includes/error.h"
 
void    ft_error(char *error)
{
    printf("Error: %s\n", error);
    exit(-1);
}

void free_map(char **map)
{
    size_t i;

    i = 0;
    if (map)
    {
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
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
    free_map(temp->map);
    free(temp);
    ft_error(error);
}

void free_data_err(char *error, t_temp *temp, t_cub3d *data, int select)
{
    free(data);
    free_tmp_err(error, temp, 0);
}