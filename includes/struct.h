#ifndef STRUCT_H
# define STRUCT_H

# include <stddef.h>

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_map
{
	size_t			w;
	size_t			h;
	char		**map;
}				t_map;

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
	t_map		map;
}				t_temp;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	void		*addr;
	int			bpp;
	int			length;
	int			endian;
}				t_mlx;

typedef struct	s_cub3d
{
	t_mlx		mlx;
	t_point		pos;
	double		fov;
	double		angle;
	double		stepRad;
	t_map		map;
	char		*text_sprite;
	char		*text_n;
	char		*text_s;
	char		*text_e;
	char		*text_w;
	int			color_ceil;
	int			color_floor;
	t_point		def;
}				t_cub3d;

typedef struct	s_ray
{
	int			up;
	int			left;
	t_point		h_intersect;
	t_point		v_intersect;
	t_point		intersect;
	double		rayAngle;
	double		stepX;
	double		stepY;
	int			dir;
	int			text_dir;
}				t_ray;

void	init_temp(t_temp *temp, int fd);
void	free_temp(t_temp *temp);
void	init_cub3d(t_cub3d *data);
void 	init_ray(t_ray *ray);
void	init_point(t_point *point);
void	init_map(t_map *map);
void 	free_map(t_map *map);
void	init_mlx(t_mlx *mlx);

#endif
