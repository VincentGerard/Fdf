/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:18:00 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 11:30:51 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_trim_start(const char *str, const char *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_strchr(set, str[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

size_t	ft_get_trim_end(const char *str, const char *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_strchr(set, str[ft_strlen(str) - i - 1]) == 0)
			break ;
		i++;
	}
	return (ft_strlen(str) - i);
}

char	*ft_strtrim(char const *str, const char *set)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (str == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(str));
	i = ft_get_trim_start(str, set);
	j = ft_get_trim_end(str, set);
	if (i >= j)
		return (ft_strdup(""));
	res = (char *)malloc(j - i + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, str + i, j - i + 1);
	return (res);
}
