#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#define abs(a) a >= 0 ? a : a * -1
	// int fd;

	// fd = open("anyfile", O_RDONLY);
	// if (fd == -1)
	// {
	// 	ft_error("test");
	// }

#include "fdf.h"


void bba(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int Yfactor = y2 < y1 ? -1 : 1;
	int Xfactor = x2 < x1 ? -1 : 1;
	int width = abs(x2 - x1);
	int height = abs(y2 - y1);
	if (width > height)
	{
		int y = y1;
		int det = (2 * height) - width; // 점화식
		for (int x = x1; x != x2; x += Xfactor)
		{
			if (det < 0) //판별
			{
				det += 2 * height;
			}
			else
			{
				y += Yfactor;
				det += (2 * height - 2 * width);
			}
			mlx_pixel_put(mlx, win, x + 300, y + 300, 0xFFFF00);
		}
	}
	else
	{
		int x = x1;
		int det2 = (2 * width) - height; // 점화식
		for (int y = y1; y != y2; y+= Yfactor)
		{
			if (det2 < 0)
			{
				det2 += 2 * width;
			}
			else
			{
				x += Xfactor;
				det2 += (2 * width - 2 * height);
			}
			mlx_pixel_put(mlx, win, x + 300, y + 300, 0xFFFF00);
		}
	}
}

void	bresenham(double start_x, double start_y, double finish_x, double finish_y, void *mlx, void *window)
{
	double width;
	double height;
	double	x;
	double	y;
	int	formula;

	width = (finish_x - start_x);
	height = (finish_y - start_y);
	x = start_x;
	y = start_y;
	formula = 2 * height - width;
	while (x < finish_x)
	{
		if (formula < 0)
			formula += (2 * height);
		else
		{
			++y;
			formula += 2 * (height - width);
		}
		mlx_pixel_put(mlx, window, x + 300 , y + 300, 0xFFFF00);
		++x;
	}
}


int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_point	**point;
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "FdF");
	// ft_check_args(argc, argv);
	map = malloc(sizeof(t_map));
	*map = rec_checker(argv[1]);
	point = make_points(map, argv[1]);

	for (int i = 0; i < map->height; ++i)
	{
		for (int j = 1; j < map->width; ++j)
		{
			bresenham(10 * point[i][j - 1].iso_x, 10 * point[i][j - 1].iso_y, 10 * point[i][j].iso_x, 10 * point[i][j].iso_y, mlx.mlx, mlx.win);
		}
	}
	for (int i = 1; i < map->height; ++i)
	{
		for (int j = 0; j < map->width; ++j)
		{
			bresenham(10 * point[i - 1][j].iso_x, 10 * point[i - 1][j].iso_y, 10 * point[i][j].iso_x, 10 * point[i][j].iso_y, mlx.mlx, mlx.win);
		}
	}
	mlx_loop(mlx.mlx);
	return (0);
	// for (int i = 0; i < map->height; ++i)
	// {
	// 	for (int j = 0; j < map->width; ++j)
	// 	{
	// 		printf("x: %f, y: %f, z: %d\n", point[i][j].iso_x, point[i][j].iso_y, point[i][j].z);
	// 	}
	// }


	/*---------파싱부 ----------*/
	//예외처리(인자 argc / 확장자 fdf)
	//파일열고 ()
	//예외처리 (직사각형이 아닌 경우)
	//파일 닫고(offset이 뒤에 위치) //clear

	//파일열고 ()
	//파싱받고 (구조체,  invalid -> digit이 아니면 예외)
	//파일 닫고(fd 누수)
	//output--> 정상 인풋데이터가 담긴 구조체 포인터 배열 pointer[x][y]

	/*---------좌표변환------------*/
	//구조체 내에 iso_x iso_y(원근 좌표계는 추가 함수를 만드는 것으로)

	/*---------그리기-----------*/
	//브리즈먼 알고리즘(옆, 아래 점 정보)

	/*---------키맵핑------------*/
	//esc 탈출
	//줌, 회전
	//원근투영으로 전환
}
