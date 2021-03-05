#ifndef CUB3D_H
# define CUB3D_H

# define MIN_RES 100
# define MAX_RES 4000

# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "struct.h"
# include "error.h"
# include "parser.h"

t_cub3d			*cub_parser(char *path);

#endif
