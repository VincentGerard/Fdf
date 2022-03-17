#include "fdf_line.h"
#include "fdf_mlx.h"
#include "fdf_map_utils_2.h"
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
		while (x < d->m_width - 1)
		{
			t_point p1;
			t_point p2;

			p1.x = 0;
			p1.y = 0;
			p2.x = 10;
			p2.y = 10;

			//fdf_mlx_connect_points(d, p2, p1);
			fdf_mlx_connect_points(d, d->p_map[y][x], d->p_map[y][x + 1]);
			if (y < d->m_height - 1)
				fdf_mlx_connect_points(d, d->p_map[y][x], d->p_map[y + 1][x]);
			x++;
		}
		y++;
	}
}

int	fdf_mlx_sign(int dxy)
{
    if(dxy<0) return -1; 
    else if(dxy>0) return 1; 
    else return 0;
}

void	fdf_mlx_connect_points(t_map_data *d, t_point s1, t_point s2)
{
	// int	delta_x;
	// int	delta_y;
	// int	x;
	// int	y;
	// int	p;
	// int	x_max;

	// if (s1.x < s2.x)
	// {
	// 	x = s1.x;
	// 	x_max = s2.x;
	// }
	// else
	// {
	// 	x = s2.x;
	// 	x_max = s1.x;
	// }
	// delta_x = x_max - x;
	// delta_y = s2.y - s1.y;
	// y = s1.y;
	// p = 2 * delta_y - delta_x;
	// printf("[S1X=%d][S1Y=%d][S2X=%d][S2Y=%d]\n", s1.x, s1.y, s2.x, s2.y);
	// printf("[DX=%d][DY=%d]\n", delta_x, delta_y);
	// printf("Line[P=%d][X=%d][XMAX=%d]\n",p, x, x_max);
	// while (x < x_max)
	// {
	// 	printf("[X=%d][Y=%d]\n",x ,y);
	// 	if (p >= 0)
	// 	{
	// 		fdf_mlx_set_pixel(d, x, y, fdf_get_hex_color(0, 255, 255, 0));
	// 		y++;
	// 		p = p + 2 * delta_y - 2 * delta_x;
	// 	}
	// 	else
	// 	{
	// 		fdf_mlx_set_pixel(d, x, y, fdf_get_hex_color(0, 255, 255, 0));
	// 		p = p + 2 * delta_y;
	// 	}
	// 	x++;
	// }
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
        	fdf_mlx_set_pixel(d, X, Y, fdf_get_hex_color(0, 255, 255, 0));
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
            fdf_mlx_set_pixel(d, X, Y, fdf_get_hex_color(0, 255, 255, 0));
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
