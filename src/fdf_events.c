#include "fdf_events.h"
#include "fdf.h"

int	fdf_event_on_destroy(void *param)
{
	if (param != NULL)
		fdf_free_and_exit((void *)param);
	return (0);
}

int	fdf_event_on_keypress(int keycode, void *param)
{
	ft_printf("[Fdf_Event_On_Keypress] = %d\n", keycode);
	if (keycode == KEY_ESCAPE)
		fdf_free_and_exit((void *)param);
	return (0);
}
