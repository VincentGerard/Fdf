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
#include "mlx.h"
#include "mlx_int.h"
#include "fdf_image.h"
 
int	fdf_event_on_destroy(void *param)
{
	if (param != NULL)
		fdf_free_and_exit((void *)param, EXIT_CODE_NORMAL);
	return (0);
}

int	fdf_event_on_expose(void *param)
{
	ft_printf("[Fdf_Event_On_Expose]\n");
	return (0);
}

int	fdf_event_on_resize(void *param)
{
	ft_printf("[Fdf_Event_On_Resize]\n");
	t_map_data *data = (t_map_data *)param;
	//fdf_put_image(data);
	return (0);
}

int	fdf_event_on_all(void *param)
{
	ft_printf("[Fdf_Event_On_All]\n");
	return (0);
}

int	fdf_event_on_keypress(int keycode, void *param)
{
	ft_printf("[Fdf_Event_On_Keypress] = %d\n", keycode);
	if (keycode == KEY_ESCAPE)
		fdf_free_and_exit((void *)param, EXIT_CODE_NORMAL);
	return (0);
}
