/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:17:46 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 11:17:46 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	char	*last;
	char	c;

	c = (unsigned char)character;
	last = NULL;
	while (*str != '\0')
	{
		if (*str == c)
			last = (char *)str;
		str++;
	}
	if (*str == '\0' && c == '\0')
		return ((char *)str);
	return (last);
}
