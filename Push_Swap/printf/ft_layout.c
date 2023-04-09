/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_layout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:26:24 by aanouari          #+#    #+#             */
/*   Updated: 2022/11/24 18:58:25 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_layout(const char *str, va_list arg)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (*str == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (*str == 'd' || *str == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (*str == 'u')
		len += ft_putunbr(va_arg(arg, unsigned int));
	else if (*str == 'X' || *str == 'x')
		len += ft_puthexnbr(va_arg(arg, unsigned int), *str == 'X');
	else if (*str == 'p')
	{
		len += ft_putstr("0x");
		len += ft_puthexnbr(va_arg(arg, unsigned long), 0);
	}
	else if (*str == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(*str);
	return (len);
}
