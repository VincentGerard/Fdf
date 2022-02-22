/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:15:44 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 11:15:50 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		size;
	char		*res;
	size_t		i;

	i = 0;
	size = ft_strlen(src);
	res = (char *)malloc(size + 1);
	if (res == 0)
		return (0);
	else
	{
		while (i < size + 1)
		{
			res[i] = '0';
			i++;
		}
		ft_strlcpy(res, src, ft_strlen(res));
	}
	res[size] = '\0';
	return (res);
}
