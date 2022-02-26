#include "fdf_hook.h"
#include "fdf_events.h"
#include "libft.h"

int	fdf_hook_all(t_map_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->mlx_win, MLX_EVENT_DESTROY, 0, fdf_event_on_destroy, data);
	mlx_key_hook(data->mlx_win, fdf_event_on_keypress, data);
}

