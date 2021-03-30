#include <math.h>

double  deg2rad(double deg)
{
    return (deg * M_PI / 180);
}

double  rad2deg(double rad)
{
    return (rad * 180 / M_PI);
}

double  round_rad(double rad)
{
    while (rad >= 2 * M_PI)
        rad -= 2 * M_PI;
    while (rad < 0)
        rad += 2 * M_PI;
    return (rad);
}

/*int main(int argc, char **argv)
{
	double in;
	double rad;
	double round;
	double deg;

	in = (double)ft_atoi(argv[1]);
	rad = deg2rad(in);
	round = round_rad(rad);
	deg = rad2deg(round);
	//printf("in: %f° rad: %frad round: %frad deg: %f°\n", in, rad, round, deg);
	return (0);
}*/