#include "../includes/cub3d.h"

static void copy_map(char **dest, char **src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
}

void    parse_map(t_temp *temp)
{
    char **tmp;
    size_t size;
    int ret;

    size = 1;
    if(!(temp->map = malloc(sizeof(char*) * (size + 1))))
        free_tmp_err(strerror(errno), temp, 1);
    temp->map[size] = NULL;
    temp->map[size - 1] = ft_strdup(temp->line);
    while ((ret = get_next_line(temp->fd, &(temp->line))))
    {
        if (ret == -1)
            free_tmp_err(strerror(errno), temp, 0);
        size++;
        if (!(tmp = malloc(sizeof(char*) * (size + 1))))
            free_tmp_err(strerror(errno), temp, 1);
        tmp[size] = NULL;
        copy_map(tmp, temp->map);
        if(!(tmp[size - 1] = ft_strdup(temp->line)))
            free_tmp_err(strerror(errno), temp, 1);
        free(temp->map);
        temp->map = tmp;
        free(temp->line);
    }
}