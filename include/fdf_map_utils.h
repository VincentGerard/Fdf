/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:04:04 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/27 16:57:24 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_UTILS_H
# define FDF_MAP_UTILS_H

//Open's file and gets maps width and height
int		fdf_get_map_size(const char *filename,
			unsigned int *width, unsigned int *height);

//Fils map data from file
int		fdf_load_map(int **map, const char *filename);

//Allocates map using width and height
int		**fdf_alloc_map(unsigned int width, unsigned int height);

//Free's map using height (using array of pointer of pointer method)
void	fdf_free_map(int **map, unsigned int height);

//Display's map in the terminal
void	fdf_show_map(int **map, unsigned int width, unsigned int height);

#endif