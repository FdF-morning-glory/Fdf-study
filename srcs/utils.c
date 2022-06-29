#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include "fdf.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int	ft_open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("read fail");
	return (fd);
}

void	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		ft_error("wrong arguments");
	i = 0;
	while (argv[1][i] != '.')
	{
		if (argv[1][i] == '\0')
			ft_error("wrong file");
		i++;
	}
	if (ft_strncmp(argv[1] + i, ".fdf\0", 5) != 0)
		ft_error("wrong name");
}


t_map	rec_checker(char *file_name)
{
	char	*line;
	int		col_count;
	int		row_count;
	t_map	map;
	int		fd;

	fd = ft_open_file(file_name);
	line = get_next_line(fd);
	col_count = ft_word_count(line, " \t\n");
	row_count = 0;
	while (line)
	{
		if (ft_word_count(line, " \t\n") != col_count)
			ft_error("invalid map");
		++row_count;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	line = NULL; //지워도 됨
	map.width = col_count;
	map.height = row_count;
	printf("col : %d, row  %d\n", map.width, map.height);
	return (map);
}

