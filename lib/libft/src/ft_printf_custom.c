/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_custom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:40:18 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/28 16:36:54 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Printfs a pointer's adress
int	ft_printf_pointer(unsigned long long int pointer)
{
	int					nbr;

	nbr = 0;
	nbr += ft_putchar('0');
	nbr += ft_putchar('x');
	nbr += ft_put_pointer(pointer, "0123456789abcdef");
	return (nbr);
}

//Printfs int in hexa, mode 0 = lowercase, mode 1 = uppercase
int	ft_printf_hexa(int number, int mode)
{
	if (mode == 0)
		return (ft_putnbr_base(number, "0123456789abcdef"));
	else
		return (ft_putnbr_base(number, "0123456789ABCDEF"));
}

int	ft_put_pointer(unsigned long long int number, char *base)
{
	int	size;
	int	lenght;

	size = 0;
	lenght = ft_strlen(base);
	if (lenght == 0)
		return (0);
	if (number >= (unsigned long long int) lenght)
	{
		size += ft_put_pointer(number / lenght, base);
		size += ft_put_pointer(number % lenght, base);
	}
	else
	{
		ft_putchar(base[number]);
		size++;
	}
	return (size);
}
