#include "fdfMapUtils.h"

int	fdf_get_map_size(const char *filename, unsigned int *width, unsigned int *height)
{
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd == 0)
		return (1);
	str = get_next_line(fd);
	*width = ft_nbr_words(str, ' ');
	while (1)
	{
		if (str == NULL)
			break;
		free(str);
		str = get_next_line(fd);
		*height = *height + 1;
	}
	close(fd);
	return (0);
}

void	fdf_init_map(int **map, unsigned int width, unsigned int height, int value)
{
	int	x;
	int y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			map[y][x] = value;
			x++;
		}
		y++;
	}
}

int	fdf_load_map(int **map, const char* filename)
{
	int		fd;
	char	*str;
	char	**temp;
	int		x;
	int		y;
	
	fd = open(filename, O_RDONLY);
	if (fd == 0)
		return (1);
	str = get_next_line(fd);
	x = 0;
	y = 0;
	while (str != NULL)
	{
		temp = ft_split(str, ' ');
		if (temp == NULL)
		{
			ft_printf("[Fdf_Load_Map]Error of split on str=%d\n", str);
			return (1);
		}
		x = 0;
		while (temp[x] != NULL)
		{
			map[y][x] = ft_atoi(temp[x]);
			free(temp[x]);
			x++;
		}
		free(temp);
		free(str);
		str = get_next_line(fd);
		y++;
	}
	close(fd);
	return (0);
}

int		**fdf_alloc_map(unsigned int width, unsigned int height)
{
	int	**map;
	unsigned int	y;

	map = (int **)malloc(sizeof(int*) * height);
	if (map == NULL)
	{
		ft_printf("[Fdf][Fdf_Alloc_Map]Error of malloc on map with height=%d, width=%d\n", height, width);
		return (NULL);
	}
	y = 0;
	while (y < height)
	{
		map[y] = (int*)malloc(sizeof(int) * width);
		if (map[y] == NULL)
		{
			ft_printf("[Fdf][Fdf_Alloc_Map]Error of malloc on map[y=%d]\n", y);
			return (NULL);
		}
		y++;
	}
	return (map);
}

void	fdf_free_map(int **map, unsigned int height)
{
	unsigned int	y;

	y = 0;
	while(y < height)
	{
		//ft_printf("Free Y=%d\n", y);
		free(map[y]);
		y++;
	}
	free(map);
}

void	fdf_show_map(int **map, unsigned int width, unsigned int height)
{
	for (unsigned int y = 0; y < height; y++)
	{
		for(unsigned int x = 0; x < width; x++)
		{
			#ifdef _STDIO_H
				printf("%2d ", map[y][x]);
			#else
				ft_printf("%d ", map[y][x]);
			#endif
		}
		#ifdef _STDIO_H
			printf("\n");
		#else
			ft_printf("\n");
		#endif
	}
}