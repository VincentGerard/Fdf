/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:01:20 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 11:01:45 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int character, size_t n)
{
	size_t			i;
	unsigned char	c;
	unsigned char	*s2;

	i = 0;
	c = (unsigned char)character;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if (s2[i] == c)
			return ((void *)&s2[i]);
		i++;
	}
	return (NULL);
}
