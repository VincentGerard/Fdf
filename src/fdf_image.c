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
#include "fdf_map_utils_3.h"
#include "fdf_mlx.h"
#include "fdf_offset.h"
#include "mlx.h"
#include <math.h>

void	fdf_put_image(t_map_data *d)
{
	int		x;
	int		y;
	t_point	*point;
	t_point	offset;

	mlx_destroy_image(d->mlx, d->c_image->image);
	d->c_image->image = mlx_new_image(d->mlx, d->w_width, d->w_height);
	d->c_image->address = mlx_get_data_addr(d->c_image->image,
			&(d->c_image->bits_per_pixel), &(d->c_image->line_length),
			&(d->c_image->endian));
	fdf_map_calc_pixel(d);
	offset = fdf_map_calc_offset(d);
	fdf_map_apply_offset(d, offset);
	fdf_draw_map_pixels(d);
	fdf_draw_map_lines(d);
	mlx_put_image_to_window(d->mlx, d->mlx_win,
		d->c_image->image, 0, 0);
}

void	fdf_draw_map_pixels(t_map_data *d)
{
	t_point	*point;
	int		x;
	int		y;

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
			point->y = (int)(((c.x * cell_offset + c.y * cell_offset)
						/ tan(fdf_degree_to_radian(60))))
				- (d->map[c.y][c.x].z * d->height_offset);
			c.x++;
		}
		c.y++;
	}
}
