/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:16:45 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 11:17:08 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (str == NULL || f == NULL)
		return (NULL);
	i = 0;
	res = (char *)malloc(ft_strlen(str) + 1);
	if (res == NULL)
		return (NULL);
	while (str[i])
	{
		res[i] = f(i, str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
