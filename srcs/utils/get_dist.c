#include <math.h>
#include "struct.h"

double	get_dist(t_point *f, t_point *t)
{
	return (sqrt(pow(f->x - t->x, 2) + pow(f->y - t->y, 2)));
}