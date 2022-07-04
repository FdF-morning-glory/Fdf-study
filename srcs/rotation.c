#include "fdf.h"
#include <math.h>

void	rotate_x(double y, double z, t_point *point, double angle)
{
	
	point->iso_y = y * cos(angle * M_PI / 300) + (z) * sin(angle * M_PI / 300);
	point->rotated_z = -y * sin(angle * M_PI / 300) + (z) * cos(angle * M_PI / 300);
}

void	rotate_y(double x, double z, t_point *point, double angle)
{
	point->iso_x = x * cos(angle * M_PI / 300) + (z) * sin(angle * M_PI / 300);
	point->rotated_z = -x * sin(angle * M_PI / 300) + (z) * cos(angle * M_PI / 300);
}

void	rotate_z(double x, double y, t_point *point, double angle)
{
	point->iso_x = x * cos(angle * M_PI / 300) - y * sin(angle * M_PI / 300);
	point->iso_y = x * sin(angle * M_PI / 300) + y * cos(angle * M_PI / 300);
}

