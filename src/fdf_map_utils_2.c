/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:04:26 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/31 12:27:02 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include "fdf_map_utils_2.h"
#include "fdf_map_utils_3.h"
#include "fdf_map_utils.h"

int	fdf_fill_map_cell(t_point **map, char *str, int row, int x)
{
	int		color;
	char	**temp2;

	if (ft_strchr(str, ','))
	{
		temp2 = ft_split(str, ',');
		if (temp2 != NULL && temp2[0] != NULL && temp2[1] != NULL)
		{
			fdf_fill_cell(&map[row][x], temp2);
			free(temp2[0]);
			free(temp2[1]);
			free(temp2);
		}
		else
			return (1);
	}
	else
		fdf_fill_empty_cell(map, str, row, x);
	return (0);
}

void	fdf_fill_empty_cell(t_point **map, char *str, int row, int x)
{
	map[row][x].x = 0;
	map[row][x].y = 0;
	map[row][x].z = ft_atoi(str);
	map[row][x].r = 255;
	map[row][x].g = 255;
	map[row][x].b = 255;
}

void	fdf_fill_cell(t_point *cell, char **str)
{
	int	color;

	cell->x = 0;
	cell->y = 0;
	cell->z = ft_atoi(str[0]);
	color = ft_atoi(str[1] + 2);
	cell->r = color / 10000;
	color = color - (cell->r * 10000);
	cell->g = color / 100;
	color = color - (cell->g * 100);
	cell->b = color;
}

int	fdf_fill_map_row(t_point **map, char *str, int row)
{
	char	**temp;
	int		x;

	temp = ft_split(str, ' ');
	if (temp == NULL)
	{
		ft_printf("[Fdf_Fill_Map_Row]Split error\n");
		return (1);
	}
	x = 0;
	while (temp[x] != NULL)
	{
		if (fdf_fill_map_cell(map, temp[x], row, x) == 1)
			return (1);
		free(temp[x]);
		x++;
	}
	free(temp);
	return (0);
}
