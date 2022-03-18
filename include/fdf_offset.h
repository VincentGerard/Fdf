/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_offset.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:12:22 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/18 17:14:16 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_OFFSET_H
# define FDF_OFFSET_H
#include "fdf.h"


t_point	fdf_map_calc_offset(t_map_data *d);

void	fdf_map_apply_offset(t_map_data *d, t_point offset);

#endif