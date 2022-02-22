/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:26:02 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/28 12:13:58 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//A custom remake of printf
int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	res = 0;
	va_start(args, format);
	ft_printf_parse((char *)format, args, &res);
	va_end(args);
	return (res);
}
