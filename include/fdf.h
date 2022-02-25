/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:06:34 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/25 03:43:47 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "fdf_map_utils.h"
# include "fdf_mlx.h"
# include <stdio.h>

typedef struct s_image
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_per_length;
	int		endian;
}			t_image;

typedef struct s_map_data
{
	int				**map;
	unsigned int	width;
	unsigned int	height;
	void			*mlx;
	void			*mlx_win;
	t_image			current_image;
	t_image			next_image;
}					t_map_data;

int	fdf(const char *filename);

#endif