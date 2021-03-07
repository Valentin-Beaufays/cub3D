#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_temp
{
	int			fd;
	char		*line;
	char		*trim;
	int			x;
	int			y;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			floor[3];
	int			ceiling[3];
	char		**map;
}				t_temp;

typedef struct	s_cub3d
{
	double		x;
	double		y;
	double		rotation;
	char		**map;
	char		*text_sprite;
	char		*text_n;
	char		*text_s;
	char		*text_e;
	char		*text_w;
	int			color_ceil;
	int			color_floor;
	int			def[2];
}				t_cub3d;

#endif
