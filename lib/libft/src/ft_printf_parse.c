/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:07:39 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/28 16:32:26 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

//Parses the format and args, returns the number of character's written
void	ft_printf_parse(char *format, va_list args, int *res)
{
	int	i;

	i = 0;
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0'
			&& ft_strchr("cspdiuxX%", format[i + 1]))
		{
			*res += ft_printf_symbol(format[i + 1], args);
			i++;
		}
		else
			*res += ft_putchar(format[i]);
		i++;
	}
}
