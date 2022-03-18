/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:24:27 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/18 14:01:31 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include "fdf_map_utils_2.h"
#include "fdf_map_utils.h"
#include <math.h>
#include <unistd.h>

int	fdf_fill_map_cell(t_point **map, char *str, int row, int x)
{
	int		color;
	char	**temp2;

	if (ft_strchr(str, ','))
	{
		temp2 = ft_split(str, ',');
		if (temp2 != NULL && temp2[0] != NULL && temp2[1] != NULL)
		{
			map[row][x].z = ft_atoi(temp2[0]);
			color = ft_atoi(temp2[1] + 2);
			map[row][x].r = color / 10000;
			color = color - (map[row][x].r * 10000);
			map[row][x].g = color / 100;
			color = color - (map[row][x].g * 100);
			map[row][x].b = color;
			free(temp2[0]);
			free(temp2[1]);
			free(temp2);
		}
		else
			return (1);
	}
	else
	{
		map[row][x].x = 0;
		map[row][x].y = 0;
		map[row][x].z = ft_atoi(str);
		map[row][x].r = 255;
		map[row][x].g = 255;
		map[row][x].b = 255;
	}
	return (0);
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

void	fdf_init_empty_map_data(t_map_data *data)
{
	data->map = NULL;
	data->m_width = 0;
	data->m_height = 0;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->c_image = NULL;
	data->w_width = 1920;
	data->w_height = 1080;
	data->w_name = "Fdf";
}

int	fdf_get_hex_color(int transparence, int r, int g, int b)
{
	return (transparence << 24 | r << 16 | g << 8 | b);
}

void	fdf_free_and_exit(t_map_data *data, t_EXIT_CODE code)
{
	if (code == EXIT_CODE_MALLOC_FAIL)
	{
		fdf_free_map(data->map, data->m_height);
		system("leaks fdf");
		exit(code);
	}
	else if (code == EXIT_CODE_NORMAL)
	{
		fdf_free_map(data->map, data->m_height);
		mlx_destroy_image(data->mlx, data->c_image->image);
		mlx_destroy_window(data->mlx, data->mlx_win);
		free(data->c_image);
		free(data->mlx);
		//system("leaks fdf");
		exit(0);
	}
}

double	fdf_degree_to_radian(double degree)
{
	return (degree * (M_PI / 180.0));
}
