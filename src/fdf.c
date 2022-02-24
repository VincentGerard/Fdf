#include "fdf.h"
#include "libft.h"

int	fdf(const char *filename)
{
	unsigned int	height;
	unsigned int	width;
	int				**map;

	height = 0;
	width = 0;

	if (fdf_get_map_size(filename, &width, &height))
	{
		ft_printf("[Fdf]Error while loading map size!\n");
		return (1);
	}
	ft_printf("[Fdf]Width=%d\n[Fdf]Height=%d\n", width, height);

	map = fdf_alloc_map(width, height);
	if (map == NULL)
	{
		ft_printf("[Fdf]Error on Fdf_Alloc_Map\n");
		return (1);
	}

	fdf_init_map(map, width, height, 0);

	if (fdf_load_map(map, filename))
	{
		ft_printf("[Fdf]Error while loading map!\n");
		fdf_free_map(map, height);
		return (1);
	}

	fdf_show_map(map, width, height);

	fdf_display_map(map, width, height);

	fdf_free_map(map,height);
	
	return (0);
}
