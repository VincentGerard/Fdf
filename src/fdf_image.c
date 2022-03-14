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

void	fdf_put_image(t_map_data *d)
{
	fdf_draw_image(d);
	mlx_put_image_to_window(d->mlx, d->mlx_win,
		d->c_image->image, 0, 0);
}

void	fdf_draw_image(t_map_data *d)
{
	fdf_draw_lines(d);
	fdf_draw_map(d);
	fdf_mlx_set_pixel(d, d->w_width / 2,
		d->w_height / 2, fdf_get_hex_color(0, 255, 0, 0));
}

void	fdf_draw_lines(t_map_data *d)
{
	int	x;
	int	y;
	int	angle;

	x = d->w_width / 2;
	y = 0;
	while (y <= d->w_height / 2)
	{
		fdf_mlx_set_pixel(d, x, y, fdf_get_hex_color(0, 0, 0, 255));
		y++;
	}

	x = 0;
	y = 0;
	angle = 60;
	while ((int)((x) / tan(fdf_degree_to_radian(angle)) + d->w_height / 2) < d->w_height)
	{
		fdf_mlx_set_pixel(d, x + d->w_width / 2, (int)((x) / tan(fdf_degree_to_radian(angle)) + d->w_height / 2), fdf_get_hex_color(0, 0, 0, 255));
		x++;
		y++;
	}

	//Left
	x = 0;
	y = 0;
	angle = 60;
	while (x < d->w_width / 2)
	{
		//Calculate new x and y
		//printf("X=%dY=%d\n", x, y);
		//printf("X=%dY=%d\n", x + d->w_width / 2, ((x / tan(fdf_degree_to_radian(60))) * -1) + d->w_height / 2);
		fdf_mlx_set_pixel(d, (x * -1) + d->w_width / 2, ((x / tan(fdf_degree_to_radian(60)))) + d->w_height / 2, fdf_get_hex_color(0, 0, 0, 255));
		x++;
	}
}

void	fdf_draw_map(t_map_data *d)
{
	unsigned int	b_height;
	unsigned int	b_width;
	t_point			c;
	t_point			*point;

	b_height = d->w_width / d->m_width / 2;
	b_width = d->w_height / d->m_height / 2;
	c.y = 0;
	while (c.y < d->m_height)
	{
		c.x = 0;
		while (c.x < d->m_width)
		{
			point = &d->p_map[c.y][c.x];
			point->x = ((c.x * b_width) + d->w_width / 2) - c.y * b_height;
			point->y = (((c.x * b_width + c.y * b_height)
						/ tan(fdf_degree_to_radian(60))) + d->w_height / 2)
				- d->map[c.y][c.x];
			fdf_mlx_set_pixel(d, point->x, point->y,
				fdf_get_hex_color(0, 255, 0, 0));
			c.x++;
		}
		c.y++;
	}
	fdf_draw_map_lines(d);
}

void	fdf_draw_map_lines(t_map_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->m_height - 1)
	{
		x = 0;
		while (x < d->m_width - 1)
		{
			fdf_mlx_connect_points(d, d->p_map[y][x], d->p_map[y][x + 1]);
			fdf_mlx_connect_points(d, d->p_map[y][x], d->p_map[y + 1][x]);
			x++;
		}
		y++;
	}
}

void	fdf_mlx_connect_points(t_map_data *d, t_point s1, t_point s2)
{
	t_point p1;
	t_point p2;
	float	angle;

	if (s1.x < s2.x)
	{
		p1.x = s1.x;
		p2.x = s2.x;
	}
	else
	{
		p1.x = s2.x;
		p2.x = s1.x
	}

	angle = (float)(s2.x - s1.x) / (float)(s2.y - s1.y);
	if (angle < 0)
	{
		printf("[X1=%d][Y1=%d][X2=%d][Y2=%d]\n", s1.x, s1.y, s2.x, s2.y);
	}
	printf("Angle:%f\n", angle);
}
