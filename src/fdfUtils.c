#include "fdf_utils.h"

int	fdf_get_map_size(const char *filename, unsigned int *height, unsigned int *width)
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
		str = get_next_line(fd);
		*height = *height + 1;
	}
	close(fd);
	return (0);
}

int	fdf_load_map(int **map, const char* filename, unsigned int height, unsigned int width)
{
	(void)map;
	(void)filename;
	(void)height;
	(void)width;
	// int		fd;
	// char	*str;
	// char	**temp;

	// fd = open(filename, O_RDONLY);
	// if (fd == 0)
	// 	return (1);
	// str = get_next_line(fd);
	// while (str != NULL)
	// {
	// 	temp = ft_split(str, ' ');
	// }
	// close(fd);
	return (0);
}
