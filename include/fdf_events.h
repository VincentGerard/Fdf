#ifndef FDF_EVENTS_H
#define FDF_EVENTS_H

int	fdf_event_on_destroy(void *param);

int	fdf_event_on_expose(void *param);

int	fdf_event_on_resize(void *param);

int	fdf_event_on_all(void *param);

int	fdf_event_on_keypress(int keycode, void *param);

#endif