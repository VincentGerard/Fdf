/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:42:03 by vgerard           #+#    #+#             */
/*   Updated: 2022/02/27 00:14:41 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

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
	}
	return (0);
}
