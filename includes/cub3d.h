#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "./parser.h"
# include "./error.h"

typedef struct	s_data
{

	int			err;
	int			x;
	int			y;
	char		*prev_line;

}				t_data;

void			ft_error(char *error);
t_data			*cub_parser(char *path);

#endif
