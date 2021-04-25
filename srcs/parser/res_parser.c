
#include "struct.h"
#include "error.h"
#include "libft.h"

static int	get_num(int *num, char *line)
{
	*num = ft_atoi(line);
	if (*line == '+' || *line == '-' || !(*num))
		return (0);
	return (1);
}

void	parse_resolution(t_temp *temp)
{
	char	*line;

	line = temp->trim + 1;
	if (!(*line == ' '))
		free_tmp_err("invalid R line", temp, 3);
	while (*line == ' ')
		line++;
	if (!get_num(&temp->x, line))
		free_tmp_err("invalid R line", temp, 3);
	while (ft_isdigit(*line))
		line++;
	if (!(*line == ' '))
		free_tmp_err("invalid R line", temp, 3);
	while (*line == ' ')
		line++;
	if (!get_num(&temp->y, line))
		free_tmp_err("invalid R line", temp, 3);
	while (ft_isdigit(*line))
		line++;
	while (*line)
	{
		if (!(*line == ' '))
			free_tmp_err("invalid R line", temp, 3);
		line++;
	}
	temp->count++;
}