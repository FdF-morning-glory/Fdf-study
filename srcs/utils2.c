#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>


void	get_one_line(char * a_line, int width)
{
	while(j < width)
	
		while (*a_line == ' ')
			a_line++
		pointer[j] = atoi(스페이스 를 만났을때 값을 뱉게)
	
}

t_point	**create_points(t_map *map)
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

t_point	**make_points(t_map *map, char *file_name)
{
	t_point	**point;

	point = create_points(map);
	//매트릭스 채우기(한줄씩)

	while(i < map->height)
	{
		get_one_line(gnl 결과물(개행기준) , );
		i++;
	}
}