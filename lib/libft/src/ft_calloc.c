/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:44:00 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 10:44:28 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	nmem, size_t n)
{
	void		*temp;

	if (nmem == 0 || n == 0)
		return (malloc(4));
	temp = malloc(nmem * n);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, nmem * n);
	return (temp);
}
