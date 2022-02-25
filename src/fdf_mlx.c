/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:39:03 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/25 14:51:20 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_mlx.h"

int	fdf_mlx(t_map_data *data)
{
	//data->mlx = mlx_init();
	//data->c_image = mlx_new_window(data->mlx, data->w_width,
			//data->w_height, data->w_name);
	//data->c_image = mlx_new_image(data->mlx, data->w_width, data->w_height);
	//data->c_image->address = mlx_get_data_addr(data->mlx,
			//&(data->c_image->bits_per_pixel), &(data->c_image->line_length),
			//&(data->c_image->endian));
	//Set image colors
	//fdf_mlx_set_pixel(data->c_image, 5, 5, fdf_get_hex_color(0, 0, 0, 255));




	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);

	
	return (0);
}

void	fdf_mlx_set_pixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
