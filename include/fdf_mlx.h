/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:39:24 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/27 00:43:09 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MLX_H
# define FDF_MLX_H
# include "fdf.h"

//Fdf mlx loop
void	fdf_mlx(t_map_data *map_data);

//Prints single pixel to map
void	fdf_mlx_set_pixel(t_image *data, int x, int y, int color);

#endif