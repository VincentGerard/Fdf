/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:19:12 by vgerard           #+#    #+#             */
/*   Updated: 2022/03/25 15:19:12 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_line.h"
#include "fdf_mlx.h"
#include "fdf_map_utils_2.h"
#include "fdf_map_utils_3.h"
#include "math.h"
#include "stdlib.h"

void	fdf_draw_map_lines(t_map_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->m_height)
	{
		x = 0;
		while (x < d->m_width)
		{
			if (x < d->m_width - 1)
				fdf_mlx_connect_points(d, d->map[y][x], d->map[y][x + 1]);
			if (y < d->m_height - 1)
				fdf_mlx_connect_points(d, d->map[y][x], d->map[y + 1][x]);
			x++;
		}
		y++;
	}
}

int	fdf_mlx_sign(int dxy)
{
	if (dxy < 0)
		return (-1);
	else if (dxy > 0)
		return (1);
	else
		return (0);
}

void	fdf_mlx_connect_points(t_map_data *d, t_point s1, t_point s2)
{
	int Dx = s2.x - s1.x;
    int Dy = s2.y - s1.y;

    //# Increments
    int Sx = fdf_mlx_sign(Dx); 
    int Sy = fdf_mlx_sign(Dy);

    //# Segment length
    Dx = abs(Dx); 
    Dy = abs(Dy); 
    int D = fmax(Dx, Dy);

    //# Initial remainder
    double R = D / 2;

    int X = s1.x;
    int Y = s1.y;
    if(Dx > Dy)
    {   
        //# Main loop
        for(int I=0; I<D; I++)
        {   
        	fdf_mlx_set_pixel(d, X, Y, fdf_get_hex_color(0, s1.r, s1.g, s1.b));
            //# Update (X, Y) and R
            X+= Sx; R+= Dy; //# Lateral move
            if (R >= Dx)
            {
                Y+= Sy; 
                R-= Dx; //# Diagonal move
            }
        }
    }
    else
    {
        //# Main loop
        for(int I=0; I<D; I++)
        {    
            fdf_mlx_set_pixel(d, X, Y, fdf_get_hex_color(0, s1.r, s1.g, s1.b));
            //# Update (X, Y) and R
            Y+= Sy; 
            R+= Dx; //# Lateral move
            if(R >= Dy)
            {    
                X+= Sx; 
                R-= Dy; //# Diagonal move
            }
        }
    }
}
