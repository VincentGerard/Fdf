/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:06:34 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/22 11:21:02 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "stdio.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	r;
	int	g;
	int	b;
}		t_point;

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
	t_point			**map;
	unsigned int	m_width;
	unsigned int	m_height;
	void			*mlx;
	void			*mlx_win;
	t_image			*c_image;
	int				w_width;
	int				w_height;
	char			*w_name;
	unsigned int	height_offset;
}					t_map_data;

typedef enum MLX_EVENT
{
	MLX_EVENT_KEYDOWN = 2,
	MLX_EVENT_KEYUP = 3,
	MLX_EVENT_EXPOSE = 12,
	MLX_EVENT_DESTROY = 17,
	MLX_EVENT_RESIZE = 22,
}	t_MLX_EVENT;

typedef enum KEYS
{
	KEY_ESCAPE = 65307,
	KEY_N = 0,
	KEY_PLUS = 69,
	KEY_MINUS = 78,
}	t_KEYS;

typedef enum EXIT_CODE
{
	EXIT_CODE_NORMAL = 0,
	EXIT_CODE_MALLOC_FAIL = 1,
}	t_EXIT_CODE;

int	fdf(const char *filename);

#endif