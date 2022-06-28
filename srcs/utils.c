#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
		ft_error("wrong arguments");
	// 확장자 체크
}