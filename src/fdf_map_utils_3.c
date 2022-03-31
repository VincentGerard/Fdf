/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:16:32 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/31 12:20:17 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map_utils_3.h"

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
	data->height_offset = 1;
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
		exit(code);
	}
	else if (code == EXIT_CODE_NORMAL)
	{
		fdf_free_map(data->map, data->m_height);
		mlx_destroy_image(data->mlx, data->c_image->image);
		mlx_destroy_window(data->mlx, data->mlx_win);
		free(data->c_image);
		free(data->mlx);
		exit(0);
	}
}

double	fdf_degree_to_radian(double degree)
{
	return (degree * (M_PI / 180.0));
}
