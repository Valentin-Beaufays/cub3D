#include "../includes/cub3d.h"

int get_value(char **line)
{
    int temp;

    if (**value == '+' || **value == '-')
        return (-1);
    temp = ft_atoi(*line);
    if (temp < 0 || temp > 255)
        return (-1);
    while (ft_isdigit(**line))
        *line++;
    return (temp);
}

int next_value(char **line)
{
    while (**line == ' ')
        *line++;
    if (**line != ',')
        return (0);
    *line++;
    while (**line == ' ')
        *line++;
    return (1);
}

void parse_floor(t_temp *temp)
{
    char *line;

    line = temp->trim + 1;
    if (!(*line == ' '))
        free_tmp_err("invalid floor line", temp, 3);
    while (*line == ' ')
        line++;
    if ((temp->floor_R = get_value(&line)) < 0)
		free_tmp_err("invalid floor line", temp, 3);
    if (!(next_value(&line)))
        free_tmp_err("missing \',\' in floor line", temp, 3);
    if ((temp->floor_G = get_value(&line)) < 0)
		free_tmp_err("invalid floor line", temp, 3);
    if (!(next_value(&line)))
        free_tmp_err("missing \',\' in floor line", temp, 3);
    if ((temp->floor_B = get_value(&line)) < 0)
		free_tmp_err("invalid floor line", temp, 3);
    while (*line)
    {
        if (*line != ' ')
            free_tmp_err("invalid floor line", temp, 3);
        line++;
    }
}

void parse_ceiling(t_temp *temp)
{
    char *line;

    line = temp->trim + 1;
    if (!(*line == ' '))
        free_tmp_err("invalid ceiling line", temp, 3);
    while (*line == ' ')
        line++;
    if ((temp->ceiling_R = get_value(&line)) < 0)
		free_tmp_err("invalid ceiling line", temp, 3);
    if (!(next_value(&line)))
        free_tmp_err("missing \',\' in ceiling line", temp, 3);
    if ((temp->ceiling_G = get_value(&line)) < 0)
		free_tmp_err("invalid ceiling line", temp, 3);
    if (!(next_value(&line)))
        free_tmp_err("missing \',\' in ceiling line", temp, 3);
    if ((temp->ceiling_B = get_value(&line)) < 0)
		free_tmp_err("invalid ceiling line", temp, 3);
    while (*line)
    {
        if (*line != ' ')
            free_tmp_err("invalid floor line", temp, 3);
        line++;
    }
}