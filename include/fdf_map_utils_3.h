/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_3.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:13:59 by vgerard           #+#    #+#             */
/*   Updated: 2022/04/08 17:17:04 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_UTILS_3_H
# define FDF_MAP_UTILS_3_H
# include "fdf.h"
# include "mlx.h"
# include "fdf_map_utils_2.h"
# include "fdf_map_utils.h"
# include <math.h>
# include <unistd.h>

void	fdf_init_empty_map_data(t_map_data *data);
int		fdf_get_hex_color(int transparence, int r, int g, int b);
void	fdf_free_and_exit(t_map_data *data, t_EXIT_CODE code);
double	fdf_degree_to_radian(double degree);
int		fdf_get_color_gradient(int c1, int c2, int index, int lenght);

#endif