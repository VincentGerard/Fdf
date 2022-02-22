/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:16:29 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/03 16:16:29 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*temp;

	temp = (char *)b;
	i = 0;
	while (i < len)
	{
		*temp = (char)c;
		temp++;
		i++;
	}
	return (b);
}
