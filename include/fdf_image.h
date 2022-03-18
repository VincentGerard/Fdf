/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:11:52 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/27 17:11:52 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_IMAGE_H
# define FDF_IMAGE_H
# include "fdf.h"
# include "fdf_line.h"

void	fdf_put_image(t_map_data *data);

void	fdf_draw_axes(t_map_data *data);

void	fdf_draw_map(t_map_data *data);

#endif