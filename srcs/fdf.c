#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include "fdf.h"

void	bresenham_x(int start_x, int start_y, int finish_x, int finish_y, t_mlx mlx)
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
		mlx_pixel_put(mlx.mlx, mlx.win, x + mlx.handler.delta_x , y + mlx.handler.delta_y, 0x00FF00);
		x += 1;
	}
}

void	bresenham_y(int start_x, int start_y, int finish_x, int finish_y, t_mlx mlx)
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
		mlx_pixel_put(mlx.mlx, mlx.win, x + mlx.handler.delta_x , y + mlx.handler.delta_y, 0x00FF00);
		y += 1;
	}
}


void	bresenham(int start_x, int start_y, int finish_x, int finish_y, t_mlx mlx)
{
	int width;
	int height;

	width = (finish_x - start_x);
	if (width < 0)
		width *= -1;
	height = (finish_y - start_y);
	if (height < 0)
		height *= -1;
	// printf("x: %d, y: %d\n", start_x, start_y);
	if (width > height)
	{
		if (start_x > finish_x)
			bresenham_x(finish_x, finish_y, start_x, start_y, mlx);
		else
			bresenham_x(start_x, start_y, finish_x, finish_y, mlx);
	}
	else
	{
		if (start_y > finish_y)
			bresenham_y(finish_x, finish_y, start_x, start_y, mlx);
		else
			bresenham_y(start_x, start_y, finish_x, finish_y, mlx);
	}
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	else if (keycode == KEY_UP)
		--(mlx->handler.delta_y);
	else if (keycode == KEY_DOWN)
		++(mlx->handler.delta_y);
	else if (keycode == KEY_LEFT)
		--(mlx->handler.delta_x);
	else if (keycode == KEY_RIGHT)
		++(mlx->handler.delta_x);
	else if (keycode == KEY_1)
		++(mlx->handler.angle_x);
	else if (keycode == KEY_2)
		++(mlx->handler.angle_y);
	else if (keycode == KEY_3)
		++(mlx->handler.angle_z);

	return (0);
}

void	set_mlx(t_mlx *mlx, t_map *map)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1600, 900, "FdF");
	ft_bzero(&mlx->handler, sizeof(t_handler));
	if (map->width < 20)
	{
		mlx->handler.scale = 25;
		mlx->handler.delta_x = 650;
		mlx->handler.delta_y = 400;
	}
	else if (map->width < 50)
	{
		mlx->handler.scale = 20;
		mlx->handler.delta_x = 800;
		mlx->handler.delta_y = 200;
	}
	else if (map->width < 210)
	{
		mlx->handler.scale = 4;
		mlx->handler.delta_x = 600;
		mlx->handler.delta_y = 100;
	}
	else
	{
		mlx->handler.scale = 1;
		mlx->handler.delta_x = 300;
		mlx->handler.delta_y = 100;
	}
}

int	main_loop(t_all all)
{
	t_point **point;
	t_mlx mlx;
	t_map *map;

	point = *(all.point);
	mlx = *(all.mlx);
	map = all.map;
	mlx_clear_window(mlx.mlx, mlx.win);
	for (int i = 0; i < map->height; ++i)
	{
		for (int j = 1; j < map->width; ++j)
		{
			rotate_x(&point, mlx.handler);
			rotate_y(&point, mlx.handler);
			rotate_z(&point, mlx.handler);
			ft_isometric(&point[i]->iso_x, &point[i]->iso_y, point[i]->z);
			bresenham(mlx.handler.scale * point[i][j - 1].iso_x, mlx.handler.scale * point[i][j - 1].iso_y, mlx.handler.scale * point[i][j].iso_x, mlx.handler.scale * point[i][j].iso_y, mlx);
		}
	}
	for (int i = 1; i < map->height; ++i)
	{
		for (int j = 0; j < map->width; ++j)
		{
			bresenham(mlx.handler.scale * point[i - 1][j].iso_x, mlx.handler.scale * point[i - 1][j].iso_y, mlx.handler.scale * point[i][j].iso_x, mlx.handler.scale * point[i][j].iso_y, mlx);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_point	**point;
	t_mlx	mlx;
	t_all	all;

	map = malloc(sizeof(t_map));
	*map = rec_checker(argv[1]);
	set_mlx(&mlx, map);
	point = make_points(map, argv[1]);
	all.map = map;
	all.mlx = &mlx;
	all.point = &point;

	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, key_press, &mlx);
	mlx_loop_hook(mlx.mlx, main_loop, &all);
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
