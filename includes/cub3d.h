#ifndef CUB3D_H
# define CUB3D_H

# define MIN_RES 100
# define MAX_RES 4000

#include <math.h>
# include "../libft/libft.h"
# include "./parser.h"


typedef struct s_cub3d
{
	double x;
	double y;
	double rotation;
	char **map;
	char *text_sprite;
	char *text_N;
	char *text_S;
	char *text_E;
	char *text_W;
	int color_ceil;
	int color_floor;
	int	def[2];
}				t_cub3d;

t_cub3d			*cub_parser(char *path);

#endif
