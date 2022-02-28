/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:06:34 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/28 02:19:47 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "stdio.h"

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
	unsigned int	m_width;
	unsigned int	m_height;
	void			*mlx;
	void			*mlx_win;
	t_image			*c_image;
	t_image			*n_image;
	int				w_width;
	int				w_height;
	char			*w_name;
}					t_map_data;

typedef enum 
{
	MLX_EVENT_KEYDOWN = 2,
	MLX_EVENT_KEYUP = 3,
	MLX_EVENT_EXPOSE = 12,
	MLX_EVENT_DESTROY = 17,
	MLX_EVENT_RESIZE = 22,
} MLX_EVENT;

typedef enum 
{
	KEY_ESCAPE = 65307,
} KEYS;

typedef enum 
{
	EXIT_CODE_NORMAL = 0,
	EXIT_CODE_MALLOC_FAIL = 1,
} EXIT_CODE;

int	fdf(const char *filename);

#endif