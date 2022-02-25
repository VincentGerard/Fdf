/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:36:16 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/25 03:40:17 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	fdf(const char *filename)
{
	unsigned int	height;
	unsigned int	width;
	int				**map;

	height = 0;
	width = 0;
	if (fdf_get_map_size(filename, &width, &height))
		return (1);
	map = fdf_alloc_map(width, height);
	if (map == NULL)
		return (1);
	if (fdf_load_map(map, filename))
	{
		fdf_free_map(map, height);
		return (1);
	}
	fdf_show_map(map, width, height);
	fdf_display_map(map, width, height);
	fdf_free_map(map, height);
	return (0);
}
