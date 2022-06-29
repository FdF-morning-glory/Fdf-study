#include "../libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

	// int fd;

	// fd = open("anyfile", O_RDONLY);
	// if (fd == -1)
	// {
	// 	ft_error("test");
	// }

#include "fdf.h"


// void	fdf()
// {

// }

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_point	**point;

	// ft_check_args(argc, argv);
	map = malloc(sizeof(t_map));
	*map = rec_checker(argv[1]);
	point = make_points(map, argv[1]);


	// for (int i = 0; i < map->height; ++i)
	// {
	// 	for (int j = 0; j < map->width; ++j)
	// 	{
	// 		printf("x: %d, y: %d, z: %d\n", j, i, point[i][j].z);
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
