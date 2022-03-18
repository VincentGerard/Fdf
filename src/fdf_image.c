/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:52:52 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/18 15:52:52 by vgerard          ###   ########.fr       */
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
	int		x;
	int		y;
	t_point	*point;

	fdf_draw_axes(d);
	fdf_map_calc_pixel(d);

	y = 0;
	while (y < d->m_height)
	{
		x = 0;
		while (x < d->m_width)
		{
			point = &d->map[y][x];
			fdf_mlx_set_pixel(d, point->x, point->y,
				fdf_get_hex_color(0, point->r, point->g, point->b));
			x++;
		}
		y++;
	}
	fdf_draw_map_lines(d);
	mlx_put_image_to_window(d->mlx, d->mlx_win,
		d->c_image->image, 0, 0);
}

void	fdf_draw_axes(t_map_data *d)
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

void	fdf_map_calc_pixel(t_map_data *d)
{
	unsigned int	cell_offset;
	t_point			c;
	t_point			*point;

	cell_offset = d->w_height / d->m_height / 2;
	c.y = 0;
	while (c.y < d->m_height)
	{
		c.x = 0;
		while (c.x < d->m_width)
		{
			point = &d->map[c.y][c.x];
			point->x = (c.x * cell_offset) - c.y * cell_offset;
			point->y = (((c.x * cell_offset + c.y * cell_offset)
						/ tan(fdf_degree_to_radian(60))))
				- d->map[c.y][c.x].z;
			c.x++;
		}
		c.y++;
	}
}
