#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

void	ft_error(char *str)
{
	perror(str);
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

void	rec_checker(int fd)
{
	
}
