#include "math.h"
#include "fdf.h"

void	rotate(t_point ***point, s_mlx mlx)
{
	
}

void	ft_isometric(double *x, double *y, int z, int key)
{
	int	prev_x;
	int	prev_y;
	int	theta;

	theta = (M_PI / 6);
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(theta);
	*y = (prev_x + prev_y) * sin(theta) - z;
}
