#include "fdf.h"
#include <stdlib.h>
#include "../minilibx_macos/mlx.h"

t_mlx	*set_mlx_info(void)
{
	t_mlx	*mlx_info;

	mlx_info = calloc(1, sizeof(t_mlx));
	mlx_info->mlx = mlx_init();
	mlx_info->win = mlx_new_window(mlx_info->mlx, 700, 1500, "FdF");
	return (mlx_info);
}

t_handler	*set_handler(void)
{
	t_handler	*handler;

	handler = calloc(1, sizeof(t_handler));
	handler->delta_x = 200;
	handler->delta_y = 200;
	handler->scale = 50;
	return (handler);
}

void	print_pixel(t_handler *handler, t_point **point, t_mlx *mlx_info, t_map *map)
{
	int		idx_x;
	int		idx_y;
	t_point	p_info;

	idx_x = 0;
	idx_y = 0;
	while (idx_y < map->height)
	{
		while (idx_x < map->width)
		{
			p_info = point[idx_x][idx_y];
			mlx_pixel_put(mlx_info->mlx, mlx_info->win, p_info.iso_x + handler->delta_x, p_info.iso_y + handler->delta_y, 0xFFFF00);
			++idx_x;
		}
		++idx_y;
	}
}

void	bresenham(int start_x, int start_y, int finish_x, int finish_y, void *mlx, void *window)
{
	int width;
	int height;
	int	x;
	int	y;
	int	formula;

	width = (finish_x - start_x);
	height = (finish_y - start_y);
	x = start_x;
	y = start_y;
	formula = 2 * height - width;
	if (width == 0)
		while (y < finish_y)
		{
			mlx_pixel_put(mlx, window, x + 200 , y + 200, 0xFFFF00);
			y++;
		}
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

void	print_line(t_point **point, t_map *map, t_handler *handler, t_mlx *mlx_info)
{
	int		idx_x;
	int		idx_y;
	t_point	start;
	t_point	finish;
	
	idx_x = 0;
	idx_y = 0;
	while (idx_y < map->height - 1)
	{
		while (idx_x < map->width - 1)
		{
			start = point[idx_x][idx_y];
			finish = point[idx_x + 1][idx_y + 1];
			bresenham(start.iso_x, start.iso_y, finish.iso_x, finish.iso_y, mlx_info->mlx, mlx_info->win);
			++idx_x;
		}
		++idx_y;
	}
}

void	draw(t_point **point, t_map *map, t_handler *handler, t_mlx *mlx_info)
{
	print_pixel(handler, point, mlx_info, map);
	print_line(point, map, handler, mlx_info);
	mlx_loop(mlx_info->mlx);
}