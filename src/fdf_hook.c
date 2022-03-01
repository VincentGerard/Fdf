/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:55:22 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/27 16:55:22 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_hook.h"
#include "fdf_events.h"
#include "mlx.h"

int	fdf_hook_all(t_map_data *data)
{
	int i;

	i = 2;
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->mlx_win, MLX_EVENT_DESTROY, 0, fdf_event_on_destroy, data);
	mlx_hook(data->mlx_win, MLX_EVENT_EXPOSE, 0, fdf_event_on_expose, data);
	mlx_hook(data->mlx_win, MLX_EVENT_RESIZE, (1L<<17), fdf_event_on_resize, data);
	mlx_key_hook(data->mlx_win, fdf_event_on_keypress, data);
	return (0);
}
