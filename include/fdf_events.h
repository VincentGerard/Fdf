/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:37:44 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/06 18:37:44 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_EVENTS_H
# define FDF_EVENTS_H

int	fdf_event_on_destroy(void *param);

int	fdf_event_on_expose(void *param);

int	fdf_event_on_keypress(int keycode, void *param);

#endif