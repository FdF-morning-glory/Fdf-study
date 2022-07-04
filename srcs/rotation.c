#include "fdf.h"
#include <math.h>

void	rotate_x(int y, int z, t_point *point, double angle)
{
	
	point->iso_y = y * cos(angle) + (z) * sin(angle);
	point->rotated_z = -y * sin(angle) + (z) * cos(angle);
}

void	rotate_y(int x, int z, t_point *point, double angle)
{
	point->iso_x = x * cos(angle) + (z) * sin(angle);
	point->rotated_z = -x * sin(angle) + (z) * cos(angle);
}

void	rotate_z(int x, int y, t_point *point, double angle)
{
	point->iso_x = x * cos(angle) - y * sin(angle);
	point->iso_y = x * sin(angle) + y * cos(angle);
}

