#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include "fdf.h"

void	bresenham_x(int start_x, int start_y, int finish_x, int finish_y, void *mlx, void *window)
{
	int width;
	int height;
	int	x;
	int	y;
	int	formula;
	int Yfactor;

	width = finish_x - start_x;
	height = finish_y - start_y;
	Yfactor = 1;
	if (height < 0)
	{
		Yfactor = -1;
		height *= -1;
	}
	x = start_x;
	y = start_y;
	formula = 2 * height - width;
	while (x < finish_x)
	{
		if (formula < 0)
			formula += (2 * height);
		else
		{
			y += Yfactor;
			formula += 2 * (height - width);
		}
		mlx_pixel_put(mlx, window, x + 600 , y + 100, 255);
		x += 1;
	}
}

void	bresenham_y(int start_x, int start_y, int finish_x, int finish_y, void *mlx, void *window)
{
	int width;
	int height;
	int	x;
	int	y;
	int	formula;
	int Xfactor;
	width = finish_x - start_x;
	height = finish_y - start_y;
	Xfactor = 1;
	if (width < 0)
	{
		Xfactor = -1;
		width *= -1;
	}

	x = start_x;
	y = start_y;
	formula = 2 * width - height;
	while (y != finish_y)
	{
		if (formula < 0)
			formula += (2 * width);
		else
		{
			x += Xfactor;
			formula += 2 * (width - height);
		}
		mlx_pixel_put(mlx, window, x + 600 , y + 100, 0x00FF00);
		y += 1;
	}
}


void	bresenham(int start_x, int start_y, int finish_x, int finish_y, void *mlx, void *window)
{
	int width;
	int height;

	width = (finish_x - start_x);
	if (width < 0)
		width *= -1;
	height = (finish_y - start_y);
	if (height < 0)
		height *= -1;
	printf("x: %d, y: %d\n", start_x, start_y);
	if (width > height)
	{
		if (start_x > finish_x)
			bresenham_x(finish_x, finish_y, start_x, start_y, mlx, window);
		else
			bresenham_x(start_x, start_y, finish_x, finish_y, mlx, window);
	}
	else
	{
		if (start_y > finish_y)
			bresenham_y(finish_x, finish_y, start_x, start_y, mlx, window);
		else
			bresenham_y(start_x, start_y, finish_x, finish_y, mlx, window);
	}
}

int	key_press(int keycode)
{
	if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	return (0);
}

void	set_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1600, 900, "FdF");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_point	**point;
	t_mlx	mlx;

	set_mlx(&mlx);
	map = malloc(sizeof(t_map));
	*map = rec_checker(argv[1]);
	point = make_points(map, argv[1]);


	for (int i = 0; i < map->height; ++i)
	{
		for (int j = 1; j < map->width; ++j)
		{
			bresenham(25 * point[i][j - 1].iso_x, 25 * point[i][j - 1].iso_y, 25 * point[i][j].iso_x, 25 * point[i][j].iso_y, mlx.mlx, mlx.win);
		}
	}
	for (int i = 1; i < map->height; ++i)
	{
		for (int j = 0; j < map->width; ++j)
		{
			bresenham(25 * point[i - 1][j].iso_x, 25 * point[i - 1][j].iso_y, 25 * point[i][j].iso_x, 25 * point[i][j].iso_y, mlx.mlx, mlx.win);
		}
	}
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, key_press, 0);
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
