#include "math.h"

void	ft_isometric(double *x, double *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(M_PI/6);
	*y = (prev_x + prev_y) * cos(M_PI/3) - z;
}