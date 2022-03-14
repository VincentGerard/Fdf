/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:11:51 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/27 17:11:51 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "fdf_image.h"
#include "fdf_map_utils_2.h"
#include "fdf_mlx.h"
#include "mlx.h"
#include <math.h>

void	fdf_put_image(t_map_data *data)
{
	fdf_draw_image(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->c_image->image, 0, 0);
}

void	fdf_draw_image(t_map_data *data)
{
	fdf_draw_lines(data);
	fdf_draw_map(data);
	fdf_mlx_set_pixel(data, data->w_width / 2,
		data->w_height / 2, fdf_get_hex_color(0, 255, 0, 0));
}

void	fdf_draw_lines(t_map_data *data)
{
	int	x;
	int	y;
	int	angle;

	x = data->w_width / 2;
	y = 0;
	while (y <= data->w_height / 2)
	{
		fdf_mlx_set_pixel(data, x, y, fdf_get_hex_color(0, 0, 0, 255));
		y++;
	}

	x = 0;
	y = 0;
	angle = 60;
	while ((int)((x) / tan(fdf_degree_to_radian(angle)) + data->w_height / 2) < data->w_height)
	{
		fdf_mlx_set_pixel(data, x + data->w_width / 2, (int)((x) / tan(fdf_degree_to_radian(angle)) + data->w_height / 2), fdf_get_hex_color(0, 0, 0, 255));
		x++;
		y++;
	}

	//Left
	x = 0;
	y = 0;
	angle = 60;
	while (x < data->w_width / 2)
	{
		//Calculate new x and y
		//printf("X=%dY=%d\n", x, y);
		//printf("X=%dY=%d\n", x + data->w_width / 2, ((x / tan(fdf_degree_to_radian(60))) * -1) + data->w_height / 2);
		fdf_mlx_set_pixel(data, (x * -1) + data->w_width / 2, ((x / tan(fdf_degree_to_radian(60)))) + data->w_height / 2, fdf_get_hex_color(0, 0, 0, 255));
		x++;
	}
}

void	fdf_draw_map(t_map_data *data)
{
	unsigned int	bloc_width;
	unsigned int	bloc_height;
	unsigned int	x;
	unsigned int	y;
	unsigned int	new_x;
	unsigned int	new_y;

	bloc_width = data->w_width / data->m_width / 2;
	bloc_height = data->w_height / data->m_height / 2;

	printf("[DrawMap]W=%d, H=%d\n", bloc_width, bloc_height);
	x = 0;
	y = 0;
	while (y < data->m_height)
	{
		x = 0;
		while (x < data->m_width)
		{
			//Draw pixel
			//printf("[DrawMap]X=%d, Y=%d\n", x, y);
			new_x = ((x * bloc_height) + data->w_width / 2) - y * bloc_width;
			new_y = (((x * bloc_height + y * bloc_width) / tan(fdf_degree_to_radian(60))) + data->w_height / 2);
			//new_y = (data->w_height / 2) + y * bloc_width;
			//new_y = 
			//printf("[DrawMap]X=%d, Y=%d\n", new_x, new_y);
			if ((y == 0 && x == 1) || (y == 1 && x == 0))
			{
				printf("[X=%d][Y=%d]\n", x, y);
				printf("[new_X=%d][new_Y=%d]\n", new_x, new_y);
				printf("Angle:%lf\n",x * bloc_height / tan(fdf_degree_to_radian(60)));
			}
			fdf_mlx_set_pixel(data, new_x, new_y, fdf_get_hex_color(0, 255, 0, 0));
			//fdf_mlx_set_pixel(data, (x * -1) + data->w_width / 2, ((x / tan(fdf_degree_to_radian(60)))) + data->w_height / 2, fdf_get_hex_color(0, 0, 255, 255));

			//Connect to the lines
			x++;
		}
		y++;
	}
}
