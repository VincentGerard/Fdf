/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:40:42 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/17 08:40:42 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LINE_H
# define FDF_LINE_H
# include "fdf.h"

typedef struct t_line
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		d;
	double	r;
	int		x;
	int		y;
}	t_line;

void	fdf_mlx_connect_points(t_map_data *data, t_point s1, t_point s2);

int		fdf_mlx_sign(int dxy);

void	fdf_draw_map_lines(t_map_data *data);

void	fdf_mlx_connect_points_x(t_line l, t_map_data *d, t_point s, t_point y);

void	fdf_mlx_connect_points_y(t_line l, t_map_data *d, t_point s, t_point y);

#endif