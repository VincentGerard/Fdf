/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:16:06 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 11:16:06 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *s1, const char *s2, unsigned int n)
{
	unsigned int	size_s1;
	unsigned int	size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (n < size_s1)
		return (size_s2 + n);
	else
	{
		s1 = s1 + size_s1;
		ft_strlcpy(s1, s2, n - size_s1);
		return (size_s1 + size_s2);
	}
}
