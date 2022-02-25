/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:24:27 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/25 11:19:17 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map_utils_2.h"

int	fdf_fill_map_row(int **map, char *str, int row)
{
	char	**temp;
	int		x;

	temp = ft_split(str, ' ');
	if (temp == NULL)
	{
		ft_printf("[Fdf_Fill_Map_Row]Split error\n");
		return (1);
	}
	x = 0;
	while (temp[x] != NULL)
	{
		map[row][x] = ft_atoi(temp[x]);
		free(temp[x]);
		x++;
	}
	free(temp);
	return (0);
}

void	fdf_init_empty_map_data(t_map_data data)
{
	data.map = NULL;
	data.width = 0;
	data.height = 0;
	data.mlx = NULL;
	data.mlx_win = NULL;
	data.current_image = NULL;
	data.next_image = NULL;
	data.window_width = 720;
	data.window_height = 360;
	data.window_name = "Fdf";
}

int	fdf_get_hex_color(int transparence, int r, int g, int b)
{
	//Convert color 
}
