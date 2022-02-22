/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:15:59 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 11:16:02 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, const char *str2)
{
	char	*res;
	int		i;

	if (str1 == NULL || str2 == NULL)
		return (ft_strdup(""));
	i = 0;
	res = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (res == NULL)
		return (NULL);
	while (*str1 != '\0')
	{
		res[i] = *str1;
		i++;
		str1++;
	}
	while (*str2 != '\0')
	{
		res[i] = *str2;
		i++;
		str2++;
	}
	res[i] = '\0';
	return (res);
}
