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

typedef struct	s_map
{
	int	width;
	int	height;
}	t_map;

void	ft_error(char *str);
void	ft_check_args(int argc, char **argv);
int		ft_open_file(char *file_name);
t_map	rec_checker(char *file_name);

#endif
