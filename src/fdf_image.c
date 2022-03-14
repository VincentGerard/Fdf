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
	unsigned int	b_height;
	unsigned int	b_width;
	t_point			c;
	t_point			point;


	b_height = data->w_width / data->m_width / 2;
	b_width = data->w_height / data->m_height / 2;
	c.y = 0;
	while (c.y < data->m_height)
	{
		c.x = 0;
		while (c.x < data->m_width)
		{
			point.x = ((c.x * b_width) + data->w_width / 2) - c.y * b_height;
			point.y = (((c.x * b_width + c.y * b_height)
						/ tan(fdf_degree_to_radian(60))) + data->w_height / 2)
				- data->map[c.y][c.x];
			fdf_mlx_set_pixel(data, point.x, point.y,
				fdf_get_hex_color(0, 255, 0, 0));
			c.x++;
		}
		c.y++;
	}
	fdf_draw_map_lines(data);
}

void	fdf_draw_map_lines(t_map_data *data)
{
	t_point	p1;
	t_point	p2;
	fdf_mlx_connect_points(data, p1, p2);
}

void	fdf_mlx_connect_points(t_map_data *data, t_point s1, t_point s2)
{

}
