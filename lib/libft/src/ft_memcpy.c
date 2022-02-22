/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:01:58 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 11:01:58 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	void	*temp;
	size_t	i;

	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	temp = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*dest2 = *src2;
		dest2++;
		src2++;
		i++;
	}
	return (temp);
}
