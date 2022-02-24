#ifndef FDF_UTILS_H
#define FDF_UTILS_H

#include "fcntl.h"
#include "fdf.h"

int		fdf_get_map_size(const char* filename, unsigned int *width, unsigned int *height);
void	fdf_init_map(int **map, unsigned int width, unsigned int height, int value);
int		fdf_load_map(int **map, const char* filename);
int		**fdf_alloc_map(unsigned int width, unsigned int height);
void	fdf_free_map(int **map, unsigned int height);
void	fdf_show_map(int **map, unsigned int width, unsigned int height);

#endif