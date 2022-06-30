/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:19 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/27 15:22:19 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
​
#include "minilibx_macos/mlx.h"
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#define abs(a) a >= 0 ? a : a * -1
​
// static void	rotate_x(int *y, int *z, double alpha)
// {
// 	int	prev_y;
​
// 	prev_y = *y;
// 	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
// 	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
// }
​
// static void	rotate_y(int *x, int *z, double beta)
// {
// 	int	prev_x;
​
// 	prev_x = *x;
// 	*x = prev_x * cos(beta) + (*z) * sin(beta);
// 	*z = -prev_x * sin(beta) + (*z) * cos(beta);
// }
​
// static void	rotate_z(int *x, int *y, double gamma)
// {
// 	int	prev_x;
// 	int	prev_y;
​
// 	prev_x = *x;
// 	prev_y = *y;
// 	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
// 	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
// }
​
​
// void	dda(float x1, float y1, float x2, float y2, void *mlx, void *window, int n)
// {
// 	float dx, dy, xinc, yinc, step, i = 0.0;

//     dx = x2 - x1;
//     dy = y2 - y1;
//     // dx는 x좌표의 차이, dy는 y좌표의 차이

//     if (abs(dx) > abs(dy))
//     	step = abs(dx);
//     else
//     	step = abs(dy);
//     // dx > dy : 기울기가 1보다 작을경우
//     // dx < dy : 기울기가 1보다 클 경우

//     xinc = dx / step;
//     yinc = dy / step;
//     while (i <= step)
//     {
// 		if (n == 1)
//     		mlx_pixel_put(mlx, window, x1, y1, 0xFF0000);
// 		else
// 			mlx_pixel_put(mlx, window, x1, y1, 0xFFFFFF);
//         x1 = x1 + xinc;
//         y1 = y1 + yinc;
// 		i += 1.0;
//     }
// }
​
static void	ft_isometric(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(M_PI/6);
	*y = (prev_x + prev_y) * cos(M_PI/3) - z;
}
​
void print_pixel(int x, int y, int z, void *mlx, void *win)
{
	ft_isometric(&x, &y, z);
	// rotate_x(&y, &z, 35.26);
	// rotate_z(&x, &y, 45);
	mlx_pixel_put(mlx, win, x + 200 , y + 200, 0xFFFF00);
}
​
void	bresenham(int start_x, int start_y, int finish_x, int finish_y, void *mlx, void *window)
{
	int width;
	int height;
	int	x;
	int	y;
	int	formula;
​
	width = (finish_x - start_x);
	height = (finish_y - start_y);
	x = start_x;
	y = start_y;
	formula = 2 * height - width;
	while (x < finish_x)
	{
		if (formula > 0)
			formula += (2 * height);
		else
		{
			++y;
			formula += 2 * (height - width);
		}
		mlx_pixel_put(mlx, window, x + 200 , y + 200, 0xFFFF00);
		++x;
	}
}
​
​
int main()
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 700, 1500, "FdF");

	print_pixel(100,0,0,mlx, window);
	print_pixel(0,-100,0,mlx, window);
	print_pixel(100,-100,0,mlx, window);
	print_pixel(100,0,100,mlx, window);
	print_pixel(100,-100,100,mlx, window);
	print_pixel(0,0,100,mlx, window);
	print_pixel(0,-100,100,mlx, window);
	print_pixel(0,0,0,mlx, window);

	//브리즈먼(선그리기)
	bresenham(0,-100, 100, -100, mlx, window);

	mlx_loop(mlx);
	return (0);
}