/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:04:12 by vgerard           #+#    #+#             */
/*   Updated: 2022/09/02 10:16:36 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf_map_utils_4.h"

char	*ft_str_to_upper(char *str)
{
	char	*start;

	start = str;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (start);
}

int	fdf_rgb_selectionable(char *str, char selector)
{
	int	lenght;

	lenght = ft_strlen(str);
	if (selector == 'r' && lenght >= 6)
		return (1);
	else if (selector == 'g' && lenght >= 4)
		return (1);
	else if (selector == 'b' && lenght >= 2)
		return (1);
	return (0);
}

int	fdf_convert_ascii_to_int(char character)
{
	if (character >= 65)
		return (character - 55);
	if (character >= 48)
		return (character - 48);
	return (0);
}
