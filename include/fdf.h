/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:06:34 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/17 14:16:38 by vgerard          ###   ########.fr       */
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
	int				**map;
	t_point			**p_map;
	unsigned int	m_width;
	unsigned int	m_height;
	void			*mlx;
	void			*mlx_win;
	t_image			*c_image;
	int				w_width;
	int				w_height;
	char			*w_name;
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
}	t_KEYS;

typedef enum EXIT_CODE
{
	EXIT_CODE_NORMAL = 0,
	EXIT_CODE_MALLOC_FAIL = 1,
}	t_EXIT_CODE;

int	fdf(const char *filename);

#endif