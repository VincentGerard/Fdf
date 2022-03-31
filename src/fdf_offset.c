/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:11:34 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/31 12:01:25 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_offset.h"
#include "stdlib.h"

t_point	fdf_map_calc_offset(t_map_data *d)
{
	t_point	offset;

	if (d->m_width > d->m_height)
	{
		offset.x = d->w_width / 2 - d->map[d->m_height / 2][d->m_width / 2].x;
		offset.y = d->w_height / 2 - d->map[d->m_height / 2][d->m_width / 2].y;
	}
	else
	{
		offset.x = d->w_width / 2 - d->map[d->m_height / 2][d->m_width / 2].x;
		offset.y = d->w_height / 2 - d->map[d->m_height / 2][d->m_width / 2].y;
	}
	return (offset);
}

void	fdf_map_apply_offset(t_map_data *d, t_point offset)
{
	int		x;
	int		y;

	y = 0;
	while (y < d->m_height)
	{
		x = 0;
		while (x < d->m_width)
		{
			d->map[y][x].x += offset.x;
			d->map[y][x].y += offset.y;
			x++;
		}
		y++;
	}
}
