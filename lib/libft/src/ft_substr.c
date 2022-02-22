/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:18:42 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/11 13:33:03 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t lenght)
{
	char	*res;
	size_t	i;

	if (str == NULL)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	i = (size_t)start;
	if (lenght > ft_strlen(str))
		lenght = ft_strlen(str);
	res = malloc(lenght + 1);
	if (res == NULL)
		return (NULL);
	while (str[i] != '\0' && i < lenght + start)
	{
		res[i - start] = str[i];
		i++;
	}
	res[i - start] = '\0';
	return (res);
}
