#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	make_matrix(t_map *map, t_point *point)
{
	
}

t_point	**make_points(t_map *map, char *str)
{
	t_point	**point;
	int	i;

	point = malloc(sizeof(t_point*) * map->height);
	i = 0;
	while (i < map->height)
	{
		point[i] = malloc(sizeof(t_point) * map->width);
		i++;
	}
	return (point);
}
