#include <mlx.h>
#include "stdio.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("mlx = NULL\n");
		exit(1);
	}
	printf("Test1\n");
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	printf("Test1\n");
	mlx_loop(mlx);
	printf("Test1\n");
}