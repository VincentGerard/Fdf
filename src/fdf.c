/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:36:16 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/14 16:58:10 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include "fdf_map_utils.h"
#include "fdf_map_utils_2.h"
#include "fdf_mlx.h"

int	fdf(const char *filename)
{
	t_map_data		map_data;

	fdf_init_empty_map_data(&map_data);
	if (fdf_get_map_size(filename, &(map_data.m_width), &(map_data.m_height)))
		return (1);
	map_data.map = fdf_alloc_map(map_data.m_width, map_data.m_height);
	if (map_data.map == NULL)
		return (1);
	map_data.p_map = fdf_alloc_p_map(map_data.m_width, map_data.m_height);
	if (map_data.p_map == NULL)
		return (1);
	if (fdf_load_map(map_data.map, filename))
	{
		fdf_free_both_map(map_data.map, map_data.p_map, map_data.m_height);
		return (1);
	}
	fdf_show_map(map_data.map, map_data.m_width, map_data.m_height);
	fdf_mlx(&map_data);
	return (0);
}
