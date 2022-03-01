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
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->c_image->image, 0, 0);
	//Write strings
	mlx_string_put(data->mlx, data->mlx_win, 50, 50, fdf_get_hex_color(0, 0, 0, 255), "Fdf_Put_Image");
}

void	fdf_draw_image(t_map_data *data)
{
	fdf_draw_lines(data);
	fdf_mlx_set_pixel(data->c_image, data->w_width / 2, data->w_height / 2, fdf_get_hex_color(0, 255, 0, 0));
}

void	fdf_draw_lines(t_map_data *data)
{
	int	x;
	int	y;
	int z;
	int angle;

	//Top
	x = data->w_width / 2;
	y = 0;
	while (y <= data->w_height / 2)
	{
		fdf_mlx_set_pixel(data->c_image, x, y, fdf_get_hex_color(0, 0, 0, 255));
		y++;
	}

	//Right
	x = 0;
	y = 0;
	z = 0;
	angle = 60;
	while ((int)((x) / tan(fdf_degree_to_radian(angle)) + data->w_height / 2) < data->w_height)
	{
		fdf_mlx_set_pixel(data->c_image, x + data->w_width / 2, (int)((x) / tan(fdf_degree_to_radian(angle)) + data->w_height / 2), fdf_get_hex_color(0, 0, 0, 255));
		x++;
		y++;
	}

	//Left
	x = 0;
	y = 0;
	z = 0;
	angle = 60;
	while ((int)((x) / tan(fdf_degree_to_radian(angle)) + data->w_height / 2) < data->w_height)
	{
		//Calculate new x and y
		printf("X=%dY=%d\n", x, y);
		printf("X=%dY=%d\n", x + data->w_width / 2, (int)(x / tan(fdf_degree_to_radian(angle)) + data->w_height / 2));
		fdf_mlx_set_pixel(data->c_image, (x + data->w_width / 2) * -1, (int)((x) / tan(fdf_degree_to_radian(angle)) + data->w_height / 2), fdf_get_hex_color(0, 0, 0, 255));
		x++;
		y++;
	}

	




}