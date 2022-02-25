/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_2.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:24:16 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/25 11:18:47 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_UTILS_2_H
# define FDF_MAP_UTILS_2_H

# include "fdf_map_utils.h"
# include "fdf.h"
//# include "fdf_struct.h"

int		fdf_fill_map_row(int **map, char *str, int row);
void	fdf_init_empty_map_data(t_map_data data);
int		fdf_get_hex_color(int transparence, int r, int g, int b);

#endif