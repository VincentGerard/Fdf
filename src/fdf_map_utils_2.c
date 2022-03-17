/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:24:27 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/17 15:11:29 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include "fdf_map_utils_2.h"
#include "fdf_map_utils.h"
#include <math.h>
#include <unistd.h>

int	fdf_fill_map_row(t_point **map, char *str, int row)
{
	char	**temp;
	int		x;

	temp = ft_split(str, ' ');
	printf("[Fill]Split Ok\n");
	if (temp == NULL)
	{
		ft_printf("[Fdf_Fill_Map_Row]Split error\n");
		return (1);
	}
	x = 0;
	while (temp[x] != NULL)
	{
		printf("[Fill]String:%s\n", temp[x]);
		if (ft_strchr(temp[x], ','))
			printf("Coucou\n");
		map[row][x].x = 0;
		map[row][x].y = 0;
		map[row][x].z = ft_atoi(temp[x]);
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
	data->w_width = 720;
	data->w_height = 360;
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
		system("leaks fdf");
		exit(0);
	}
}

double	fdf_degree_to_radian(double degree)
{
	return (degree * (M_PI / 180.0));
}
