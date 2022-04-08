/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:19:12 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/25 15:19:12 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_line.h"
#include "fdf_mlx.h"
#include "fdf_map_utils_2.h"
#include "fdf_map_utils_3.h"
#include "math.h"
#include "stdlib.h"

void	fdf_draw_map_lines(t_map_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->m_height)
	{
		x = 0;
		while (x < d->m_width)
		{
			if (x < d->m_width - 1)
				fdf_mlx_connect_points(d, d->map[y][x], d->map[y][x + 1]);
			if (y < d->m_height - 1)
				fdf_mlx_connect_points(d, d->map[y][x], d->map[y + 1][x]);
			x++;
		}
		y++;
	}
}

int	fdf_mlx_sign(int dxy)
{
	if (dxy < 0)
		return (-1);
	else if (dxy > 0)
		return (1);
	else
		return (0);
}

void	fdf_mlx_connect_points(t_map_data *d, t_point s1, t_point s2)
{
	t_line	line;

	line.dx = s2.x - s1.x;
	line.dy = s2.y - s1.y;
	line.sx = fdf_mlx_sign(line.dx);
	line.sy = fdf_mlx_sign(line.dy);
	line.dx = abs(line.dx);
	line.dy = abs(line.dy);
	line.d = fmax(line.dx, line.dy);
	line.r = line.d / 2;
	line.x = s1.x;
	line.y = s1.y;
	if (line.dx > line.dy)
	{
		fdf_mlx_connect_points_x(line, d, s1, s2);
	}
	else
	{
		fdf_mlx_connect_points_y(line, d, s1, s2);
	}
}

void	fdf_mlx_connect_points_x(t_line l, t_map_data *d, t_point s, t_point s2)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (i < l.d)
	{
		r = fdf_get_color_gradient(s.r, s2.r, i, l.d);
		g = fdf_get_color_gradient(s.g, s2.g, i, l.d);
		b = fdf_get_color_gradient(s.b, s2.b, i, l.d);
		fdf_mlx_set_pixel(d, l.x, l.y,
			fdf_get_hex_color(0, r, g, b));
		l.x += l.sx;
		l.r += l.dy;
		if (l.r >= l.dx)
		{
			l.y += l.sy;
			l.r -= l.dx;
		}
		i++;
	}
}

void	fdf_mlx_connect_points_y(t_line l, t_map_data *d, t_point s, t_point s2)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (i < l.d)
	{
		r = fdf_get_color_gradient(s.r, s2.r, i, l.d);
		g = fdf_get_color_gradient(s.g, s2.g, i, l.d);
		b = fdf_get_color_gradient(s.b, s2.b, i, l.d);
		fdf_mlx_set_pixel(d, l.x, l.y,
			fdf_get_hex_color(0, r, g, b));
		l.y += l.sy;
		l.r += l.dx;
		if (l.r >= l.dy)
		{
			l.x += l.sx;
			l.r -= l.dy;
		}
		i++;
	}
}
