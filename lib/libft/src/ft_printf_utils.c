/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:07:34 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/31 09:48:17 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Printf a single character and returns 1
int	ft_putchar(char character)
{
	write(1, &character, 1);
	return (1);
}

//Printf a string and returns the amount of letters written
int	ft_putstr(char *str)
{
	int	size;
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	size = ft_strlen(str);
	while (i < size)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (size);
}

int	ft_putnbr(int nbr)
{
	int	size;
	int	c;

	size = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		size += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		size += ft_putnbr(nbr / 10);
		size += ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + 48;
		size += ft_putchar(c);
	}
	return (size);
}

int	ft_putnbr_u(unsigned int nbr)
{
	int	size;
	int	c;

	size = 0;
	if (nbr >= 10)
	{
		size += ft_putnbr(nbr / 10);
		size += ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + 48;
		size += ft_putchar(c);
	}
	return (size);
}

int	ft_putnbr_base(int number, char *base)
{
	int				size;
	int				lenght;
	unsigned int	nbr;

	nbr = (unsigned int)number;
	lenght = ft_strlen(base);
	size = 0;
	if (lenght == 0)
		return (0);
	if (nbr >= (unsigned int)lenght)
	{
		size += ft_putnbr_base(nbr / lenght, base);
		size += ft_putnbr_base(nbr % lenght, base);
	}
	else
	{
		ft_putchar(base[nbr]);
		size++;
	}
	return (size);
}
