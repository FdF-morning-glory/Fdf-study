#ifndef FDF_H
# define FDF_H

# define PI 3.14159
# include <unistd.h>

typedef struct	s_handler
{
	double	scale;
	double	angle;
	int		delta_x;
	int		delta_y;
}	t_handler;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	t_handler	handler;
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


#define X_EVENT_KEY_PRESS 2
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

void	ft_error(char *str);
void	ft_check_args(int argc, char **argv);
int		ft_open_file(char *file_name);
t_map	rec_checker(char *file_name);
size_t	ft_word_count(char const *s, char const *set);
int		is_set(char c, char const *set);
t_point	**make_points(t_map *map, char *file_name);
void	ft_isometric(double *x, double *y, int z);
#endif
