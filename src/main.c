/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:42:03 by vgerard           #+#    #+#             */
/*   Updated: 2022/04/08 11:43:47 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include "fdf_map_utils_2.h"

int	main(int argc, char const *argv[])
{
	(void)argv;
	if (argc == 2)
	{
		if (fdf(argv[1]))
		{
			ft_printf("[Main]Error in fdf!\n");
			exit(1);
		}
	}
	else
	{
		ft_printf("Fdf needs 2 args!!!\n");
		char str[] = "FF00FF";
		printf("R=%d\n", fdf_get_rbg_from_string(str, 'r'));
		printf("G=%d\n", fdf_get_rbg_from_string(str, 'g'));
		printf("B=%d\n", fdf_get_rbg_from_string(str, 'b'));
	}
	return (0);
}
