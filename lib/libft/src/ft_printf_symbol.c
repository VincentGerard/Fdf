/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_symbol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:08:27 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/28 16:37:57 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Calls the symbol sepcific functions
int	ft_printf_symbol(char character, va_list args)
{
	int	nbr;

	nbr = 0;
	if (character == 'c')
		nbr += ft_putchar(va_arg(args, int));
	else if (character == 's')
		nbr += ft_putstr(va_arg(args, char *));
	else if (character == 'p')
		nbr += ft_printf_pointer(va_arg(args, unsigned long long int));
	else if (character == 'd')
		nbr += ft_putnbr(va_arg(args, int));
	else if (character == 'i')
		nbr += ft_putnbr(va_arg(args, int));
	else if (character == 'u')
		nbr += ft_putnbr_u(va_arg(args, unsigned int));
	else if (character == 'x')
		nbr += ft_printf_hexa(va_arg(args, int), 0);
	else if (character == 'X')
		nbr += ft_printf_hexa(va_arg(args, int), 1);
	else if (character == '%')
		nbr += ft_putchar('%');
	return (nbr);
}
