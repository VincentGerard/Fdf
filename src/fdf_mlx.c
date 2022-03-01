/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:39:03 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/01 11:15:16 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include "fdf_mlx.h"
#include "fdf_map_utils_2.h"
#include "fdf_hook.h"
#include "fdf_image.h"

void	fdf_mlx(t_map_data *d)
{
	if (d->c_image == NULL)
	{
		d->c_image = (t_image *)malloc(sizeof(t_image));
		if (d->c_image == NULL)
		{
			ft_printf("[Fdf_Mlx]Error of malloc on data->c_image\n");
			fdf_free_and_exit(d, EXIT_CODE_MALLOC_FAIL);
		}
	}
	d->mlx = mlx_init();
	d->mlx_win = mlx_new_window(d->mlx, d->w_width,
			d->w_height, d->w_name);
	d->c_image->image = mlx_new_image(d->mlx, d->w_width, d->w_height);
	d->c_image->address = mlx_get_data_addr(d->c_image->image,
			&(d->c_image->bits_per_pixel), &(d->c_image->line_length),
			&(d->c_image->endian));
	fdf_put_image(d);
	fdf_hook_all(d);
	mlx_loop(d->mlx);
}

void	fdf_mlx_set_pixel(t_image *data, int x, int y, int color)
{
	char	*dst;
	printf("[Pixel]X=%dY=%d\n", x , y);
	dst = data->address + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
			
	*(unsigned int *)dst = color;
	printf("[Pixel]X=%dY=%d\n", x , y);
}
