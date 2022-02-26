#ifndef FDF_EVENTS_H
#define FDF_EVENTS_H

enum MLX_EVENT
{
	MLX_EVENT_KEYDOWN = 2,
	MLX_EVENT_KEYUP = 3,
	MLX_EVENT_DESTROY = 17,
};

enum KEYS
{
	KEY_ESCAPE = 65307,
};

int	fdf_event_on_destroy(void *param);

int	fdf_event_on_keypress(int keycode, void *param);

#endif