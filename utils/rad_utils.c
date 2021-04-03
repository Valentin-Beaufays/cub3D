#include <math.h>

double	deg2rad(double deg)
{
	return (deg * M_PI / 180);
}

double	rad2deg(double rad)
{
	return (rad * 180 / M_PI);
}

double	round_rad(double rad)
{
	while (rad >= 2 * M_PI)
		rad -= 2 * M_PI;
	while (rad < 0)
		rad += 2 * M_PI;
	return (rad);
}
