#include "fdf.h"
#include "libft.h"

int	fdf(const char *filename)
{
	unsigned int	height;
	unsigned int	width;
	int				**map;
	unsigned int	y;

	height = 0;
	width = 0;
	ft_printf("[Fdf]Filename=%s\n", filename);

	if (fdf_get_map_size(filename, &height, &width))
	{
		ft_printf("[Fdf]Error while loading map size!\n");
		return (1);
	}
	ft_printf("[Fdf]Height=%d\n[Fdf]Width=%d\n", height, width);

	//Alloc map
	map = (int **)malloc(sizeof(int*) * height);
	if (map == NULL)
	{
		ft_printf("[Fdf]Error of malloc on map with height=%d, width=%d\n", height, width);
		return (1);
	}
	y = 0;
	while (y < width)
	{
		map[y] = (int*)malloc(sizeof(int) * width);
		if (map[y] == NULL)
		{
			ft_printf("[Fdf]Error of malloc on map[y=%d]\n", y);
			return (1);
		}
		y++;
	}
	ft_printf("Ok\n");
	int k = 0;
	for (unsigned int y = 0; y < height; y++)
	{
		for(unsigned int x = 0; x < width; x++)
		{
			//ft_printf("K=%dX=%dY=%d\n",k, x ,y);
			map[y][x] = k;
			k++;
		}
	}
	// if (fdf_load_map(map, filename, height, width))
	// {
	// 	ft_printf("[Fdf]Error while loading map!\n");
	// 	free(map);
	// 	return (1);
	// }

	for (unsigned int y = 0; y < height; y++)
	{
		for(unsigned int x = 0; x < width; x++)
		{
			ft_printf("%d ", map[y][x]);
		}
		ft_printf("\n");
	}
	return (0);
}
