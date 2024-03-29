/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:04:26 by vgerard           #+#    #+#             */
/*   Updated: 2022/09/02 10:47:14 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include "fdf_map_utils_2.h"
#include "fdf_map_utils_3.h"
#include "fdf_map_utils_4.h"
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
	cell->r = fdf_get_rbg_from_string(str[1] + 2, 'r');
	cell->g = fdf_get_rbg_from_string(str[1] + 2, 'g');
	cell->b = fdf_get_rbg_from_string(str[1] + 2, 'b');
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

int	fdf_get_rbg_from_string(char *str, char selector)
{
	int		val;
	int		len;
	int		offset;
	char	c;
	char	c2;

	len = (int)ft_strlen(str);
	val = 0;
	str = ft_str_to_upper(str);
	if (!fdf_rgb_selectionable(str, selector))
		return (0);
	if (selector == 'r')
		offset = 6;
	else if (selector == 'g')
		offset = 4;
	else if (selector == 'b')
		offset = 2;
	else
		return (-1);
	c = fdf_convert_ascii_to_int(str[len - offset]);
	c2 = fdf_convert_ascii_to_int(str[len - offset + 1]);
	val = (16 * c) + c2;
	return (val);
}
