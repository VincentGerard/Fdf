/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:44:11 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/25 11:08:14 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct s_image
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_map_data
{
	int				**map;
	unsigned int	width;
	unsigned int	height;
	void			*mlx;
	void			*mlx_win;
	t_image			*c_image;
	t_image			*n_image;
	int				w_width;
	int				w_height;
	char			*w_name;
}					t_map_data;

#endif