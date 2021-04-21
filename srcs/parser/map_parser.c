#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "get_next_line.h"
#include "libft.h"
#include "struct.h"
#include "error.h"

static void		copy_map(char **dest, char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

static size_t	get_max_len(char **map)
{
	size_t	max_len;
	size_t	curr_len;
	size_t	y;

	y = 0;
	max_len = 0;
	while (map[y])
	{
		curr_len = ft_strlen(map[y]);
		if (curr_len > max_len)
			max_len = curr_len;
		y++;
	}
	return (max_len);
}

static char		*resize_line(char *line, size_t size)
{
	char	*new;
	size_t	x;

	x = 0;
	if (!(new = malloc(sizeof(char*) * size + 1)))
		return (0);
	while (line[x])
	{
		new[x] = line[x];
		x++;
	}
	while (x < size)
	{
		new[x] = ' ';
		x++;
	}
	new[x] = 0;
	return (new);
}

static int		square_map(t_map *map)
{
	size_t	y;
	char	*tmp;

	y = 0;
	map->w = get_max_len(map->map);
	while (map->map[y])
	{
		if (!(tmp = resize_line(map->map[y], map->w)))
			return (0);
		free(map->map[y]);
		map->map[y] = tmp;
		y++;
	}
	return (1);
}

void			parse_map(t_temp *temp)
{
	char	**tmp;
	int		ret;

	temp->map.h = 1;
	if (!(temp->map.map = malloc(sizeof(char*) * (temp->map.h + 1))))
		free_tmp_err(strerror(errno), temp, 1);
	temp->map.map[temp->map.h] = NULL;
	temp->map.map[temp->map.h - 1] = temp->line;
	while ((ret = get_next_line(temp->fd, &temp->line)))
	{
		if (ret == -1)
			free_tmp_err(strerror(errno), temp, 0);
		temp->map.h++;
		if (!(tmp = malloc(sizeof(char*) * (temp->map.h + 1))))
			free_tmp_err(strerror(errno), temp, 1);
		tmp[temp->map.h] = NULL;
		copy_map(tmp, temp->map.map);
		tmp[temp->map.h - 1] = temp->line;
		free(temp->map.map);
		temp->map.map = tmp;
	}
	free(temp->line);
	if (!(square_map(&temp->map)))
		free_tmp_err(strerror(errno), temp, 0);
}
