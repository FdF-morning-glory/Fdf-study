#ifndef FDF_H
# define FDF_H

# define PI 3.14159

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct	s_point
{
	int		z;
	double	iso_x;
	double	iso_y;
}	t_point;

#endif