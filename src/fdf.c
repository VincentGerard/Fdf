/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:36:16 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/27 00:42:44 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf(const char *filename)
{
	t_map_data		map_data;

	fdf_init_empty_map_data(&map_data);
	if (fdf_get_map_size(filename, &(map_data.width), &(map_data.height)))
		return (1);
	map_data.map = fdf_alloc_map(map_data.width, map_data.height);
	if (map_data.map == NULL)
		return (1);
	if (fdf_load_map(map_data.map, filename))
	{
		fdf_free_map(map_data.map, map_data.height);
		return (1);
	}
	fdf_show_map(map_data.map, map_data.width, map_data.height);
	fdf_mlx(&map_data);
	return (0);
}
