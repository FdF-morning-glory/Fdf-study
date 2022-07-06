#ifndef FDF_H
# define FDF_H

# include <unistd.h>

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		width;
	int		height;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

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

typedef struct	s_handler
{
	double	scale;
	double	angle;
	double	delta_x;
	double	delta_y;
}	t_handler;


void	ft_error(char *str);
void	ft_check_args(int argc, char **argv);
int		ft_open_file(char *file_name);
t_map	rec_checker(char *file_name);
size_t	ft_word_count(char const *s, char const *set);
int		is_set(char c, char const *set);
t_point	**make_points(t_map *map, char *file_name);
void	ft_isometric(int *x, int *y, int z);
#endif
