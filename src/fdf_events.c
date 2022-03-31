/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:52:43 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/27 16:52:43 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fdf.h"
#include "fdf_events.h"
#include "fdf_map_utils.h"
#include "fdf_map_utils_2.h"
#include "fdf_map_utils_3.h"
#include "mlx.h"
#include "fdf_image.h"

int	fdf_event_on_destroy(void *param)
{
	if (param != NULL)
		fdf_free_and_exit((void *)param, EXIT_CODE_NORMAL);
	return (0);
}

int	fdf_event_on_expose(void *param)
{
	fdf_put_image((t_map_data *)param);
	return (0);
}

int	fdf_event_on_keypress(int keycode, void *param)
{
	t_map_data	*data;

	data = (t_map_data *)param;
	if (keycode == MAC_KEY_ESCAPE || keycode == WINDOWS_KEY_ESCAPE)
		fdf_free_and_exit((void *)param, EXIT_CODE_NORMAL);
	else if (keycode == MAC_KEY_PLUS || keycode == WINDOWS_KEY_PLUS)
	{
		data->height_offset++;
		fdf_put_image(data);
	}
	else if (keycode == MAC_KEY_MINUS || keycode == WINDOWS_KEY_MINUS)
	{
		if (data->height_offset > 0)
		{
			data->height_offset--;
			fdf_put_image(data);
		}
	}
	return (0);
}
