/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:25:42 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/28 14:45:16 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdlib.h"
# include "libft.h"
# include "stdarg.h"

int		ft_printf(const char *format, ...);
void	ft_printf_parse(char *format, va_list args, int *res);
int		ft_printf_symbol(char character, va_list args);

//ft_printf_custom.c

int		ft_printf_pointer(unsigned long long int pointer);
int		ft_printf_hexa(int number, int mode);

//ft_printf_utils.c

int		ft_putchar(char character);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_putnbr_base(int number, char *base);
int		ft_put_pointer(unsigned long long int number, char *base);
int		ft_putnbr_u(unsigned int nbr);

#endif