#ifndef UTILS_H
# define UTILS_H

int		rgb_to_int(int r, int g, int b);
int		check_path(char *path, char *ext);
double	deg2rad(double deg);
double	rad2deg(double rad);
void	get_angle_dir(double angle, int *up, int *left);

#endif
