/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:17:35 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 14:25:25 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[i] != '\0' && i < n)
	{
		j = 0;
		while (str1[i + j] != '\0' && str2[j] != '\0'
			&& str1[i + j] == str2[j] && (i + j) < n)
			j++;
		if (str2[j] == '\0')
			return ((char *)(str1 + i));
		i++;
	}
	return (NULL);
}
