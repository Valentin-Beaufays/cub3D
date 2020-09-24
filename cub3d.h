#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

typedef struct	s_param
{

	int			err;
	int			x;
	int			y;
	char		*prev_line;

}				t_param;

void			ft_error(char *error);
int				cub_parser(char *path, t_param *data);

#endif
