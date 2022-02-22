/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:39:39 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 11:45:03 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_atoi_add_number(const char **str, unsigned long long *res)
{
	while (**str)
	{
		if (**str >= '0' && **str <= '9')
			*res = *res * 10 + (**str - '0');
		else
			break ;
		(*str)++;
	}
}

int	ft_atoi(const char *str)
{
	int					nbr_minus;
	unsigned long long	res;

	nbr_minus = 0;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\f'
		|| *str == '\n' || *str == '\r' || *str == '\v')
			str++;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			nbr_minus++;
	}
	ft_atoi_add_number(&str, &res);
	if (res > LLONG_MAX && nbr_minus == 0)
		return (-1);
	if (res - 1 > LLONG_MAX && nbr_minus == 1)
		return (0);
	if (nbr_minus % 2 == 1)
		res *= -1;
	return ((int)res);
}
