/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_2.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:24:16 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/18 15:55:11 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_UTILS_2_H
# define FDF_MAP_UTILS_2_H

int		fdf_fill_map_cell(t_point **map, char *str, int row, int x);
void	fdf_fill_empty_cell(t_point **map, char *str, int row, int x);
int		fdf_fill_map_row(t_point **map, char *str, int row);
void	fdf_init_empty_map_data(t_map_data *data);
int		fdf_get_hex_color(int transparence, int r, int g, int b);
void	fdf_free_and_exit(t_map_data *data, t_EXIT_CODE code);
double	fdf_degree_to_radian(double degree);

#endif