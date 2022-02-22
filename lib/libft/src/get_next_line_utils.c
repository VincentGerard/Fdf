/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:10:44 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/20 10:22:18 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	int		lenght;
	char	*res;

	lenght = ft_strlen(str1) + ft_strlen(str2);
	res = (char *)malloc(lenght + 1);
	if (res == NULL)
		return (NULL);
	while (*str1 != '\0')
	{
		*res = *str1;
		res++;
		str1++;
	}
	while (*str2 != '\0')
	{
		*res = *str2;
		res++;
		str2++;
	}
	*res = '\0';
	return (res - lenght);
}

int	ft_alloc_temp(char **temp)
{
	*temp = (char *)malloc(1);
	if (*temp == NULL)
	{
		return (1);
	}
	*temp[0] = '\0';
	return (0);
}
