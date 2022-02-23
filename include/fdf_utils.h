#ifndef FDF_UTILS_H
#define FDF_UTILS_H

#include "fcntl.h"
#include "fdf.h"

int	fdf_get_map_size(const char* filename, unsigned int *height, unsigned int *width);
int	fdf_load_map(int **map, const char* filename, unsigned int height, unsigned int width);

#endif