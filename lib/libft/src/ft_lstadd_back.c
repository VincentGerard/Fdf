/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:57:48 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 10:57:57 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	temp = *lst;
	while (temp != NULL)
	{
		if (temp->next == NULL)
		{
			temp->next = new;
			return ;
		}
		temp = temp->next;
	}
}
