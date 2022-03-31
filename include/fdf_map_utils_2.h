/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_2.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:24:16 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/31 14:43:53 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_UTILS_2_H
# define FDF_MAP_UTILS_2_H

int		fdf_fill_map_cell(t_point **map, char *str, int row, int x);
void	fdf_fill_empty_cell(t_point **map, char *str, int row, int x);
void	fdf_fill_cell(t_point *cell, char **str);
int		fdf_fill_map_row(t_point **map, char *str, int row);
int		fdf_get_rbg_from_string(char *str, char selector);

#endif