#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>

void	get_one_line(t_point *point, int y, char *a_line, int width)
{
	char	**split;
	int		i;
	char	**tmp;
	int		x;

	i = 0;
	split = ft_split(a_line, ' ');
	while(i < width)
	{
		point[i].iso_x = i;
		point[i].iso_y = y;
		point[i].z = ft_atoi(split[i]);
		i++;
	}
	tmp = split;
	while(*split)
	{
		free(*split);
		split++;
	}
	free(tmp);
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
	int		i;
	int		fd;
	char	*line;

	point = create_points(map);
	fd = ft_open_file(file_name);
	i = 0;
	while(i < map->height)
	{
		line = get_next_line(fd);
		get_one_line(point[i], i, line, map->width);
		free(line);
		i++;
	}
	close(fd);
	return (point);
}

