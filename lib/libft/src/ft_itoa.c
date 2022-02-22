/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:45:16 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/10 10:56:38 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_digits(int number)
{
	int	res;

	res = 1;
	if (number < 0)
	{
		number *= -1;
		res++;
	}
	while (number > 9)
	{
		res++;
		number /= 10;
	}
	return (res);
}

void	ft_itoa2(char *res, int *number, int *i, int *lenght)
{
	*res = '-';
	*number *= -1;
	*i = *(i) + 1;
	*lenght = *(lenght) - 1;
}

char	*ft_itoa(int number)
{
	char	*res;
	int		lenght;
	int		i;

	i = 0;
	lenght = ft_nbr_digits(number);
	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	res = malloc(lenght + 1);
	if (res == NULL)
		return (NULL);
	res[lenght] = '\0';
	if (number < 0)
	{
		ft_itoa2(&res[0], &number, &i, &lenght);
	}
	while (lenght > 0)
	{
		res[i + lenght - 1] = (number % 10) + 48;
		number /= 10;
		lenght--;
	}
	return (res);
}
