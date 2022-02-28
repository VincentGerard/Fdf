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
	x = data->w_width / 2;
	y = data->w_height / 2;
	z = 0;
	angle = 60;
	while ((int)x / tan(fdf_degree_to_radian(angle)) < data->w_height)
	{
		//Calculate new x and y
		printf("X=%dY=%d\n", x, y);
		printf("X=%dY=%d\n", x, (int)(x / tan(fdf_degree_to_radian(angle))));
		fdf_mlx_set_pixel(data->c_image, x , (int)((x) / tan(fdf_degree_to_radian(angle))), fdf_get_hex_color(0, 0, 0, 255));
		x++;
		y++;
	}

	x = data->w_width / 2;
	y = data->w_height / 2;
	z = 1;
	angle = 60;
	while ((int)(x + cos(fdf_degree_to_radian(angle)) * z) < data->w_width &&  y + sin(fdf_degree_to_radian(angle)) * z < data->w_height)
	{
		//Calculate new x and y
		printf("Coucou\n");
		printf("X=%dY=%d\n", x, y);
		printf("Angle=%lf\n" , cos(fdf_degree_to_radian(angle)));
		printf("X=%dY=%d\n", (int)(x + cos(fdf_degree_to_radian(angle)) * z),  (int)(y + sin(fdf_degree_to_radian(angle)) * z));
		fdf_mlx_set_pixel(data->c_image, x + cos(fdf_degree_to_radian(angle)) * z, y + sin(fdf_degree_to_radian(angle)) * z, fdf_get_hex_color(0, 0, 255, 0));
		x++;
		y++;
	}

	x = data->w_width / 2;
	y = data->w_height / 2;
	z = 1;
	angle = 60;
	while (x < data->w_width &&  y * (3.0 / 10.0) < data->w_height)
	{
		//Calculate new x and y
		printf("Coucou\n");
		printf("X=%dY=%d\n", x, y);
		printf("Angle=%lf\n" , cos(fdf_degree_to_radian(angle)));
		printf("X=%dY=%lf\n", x, y * (3.0 / 10.0));
		fdf_mlx_set_pixel(data->c_image, x, y * (3.0 / 10.0), fdf_get_hex_color(0, 255, 0, 0));
		x++;
		y++;
	}




}