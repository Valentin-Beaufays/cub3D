#include "../includes/cub3d.h"

int		check_path(char *path, char *ext)
{
	size_t	len;
	size_t	ext_len;

	len = ft_strlen(path);
	ext_len = ft_strlen(ext);
	if (ext_len < len)
	{
		if (ft_strcmp(path + (len - ext_len), ext))
			return (0);
	}
	return (1);
}
