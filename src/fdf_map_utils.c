/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:01:10 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/25 15:18:37 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fdf.h"
#include "fdf_map_utils.h"
#include "fdf_map_utils_2.h"

int	fdf_get_map_size(const char *filename,
unsigned int *width, unsigned int *height)
{
	int		fd;
	char	*str;

	fd = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("[Fdf_Get_Map_Size]Error while opening file %s!\n", filename);
		return (1);
	}
	str = get_next_line(fd);
	*width = ft_nbr_words(str, ' ');
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		*height = *height + 1;
	}
	close(fd);
	return (0);
}

int	fdf_load_map(t_point **map, const char *filename)
{
	int		fd;
	char	*str;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd == 0)
	{
		ft_printf("[Fdf_Load_Map]Error while opening file %s!\n", filename);
		return (1);
	}
	str = get_next_line(fd);
	y = 0;
	while (str != NULL)
	{
		if (fdf_fill_map_row(map, str, y))
			return (1);
		free(str);
		str = get_next_line(fd);
		y++;
	}
	close(fd);
	return (0);
}

t_point	**fdf_alloc_map(unsigned int width, unsigned int height)
{
	t_point			**map;
	unsigned int	y;

	map = (t_point **)malloc(sizeof(t_point *) * height);
	if (map == NULL)
	{
		ft_printf("[Fdf_Alloc_Map]Malloc on map with height=%d, width=%d\n",
			height, width);
		return (NULL);
	}
	y = 0;
	while (y < height)
	{
		map[y] = (t_point *)malloc(sizeof (t_point) * width);
		if (map[y] == NULL)
		{
			ft_printf("[Fdf_Alloc_Map]Error of malloc on map[Y=%d]\n", y);
			return (NULL);
		}
		y++;
	}
	return (map);
}

void	fdf_free_map(t_point **map, unsigned int height)
{
	unsigned int	y;

	y = 0;
	while (y < height)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	fdf_show_map(t_point **map, unsigned int width, unsigned int height)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ft_printf("%d ", map[y][x].z);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
