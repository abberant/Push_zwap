/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:26:46 by aanouari          #+#    #+#             */
/*   Updated: 2022/11/25 16:47:58 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
			len += ft_layout(++str, arg);
		else
			len += ft_putchar(*str);
		if (*str)
			str++;
	}
	va_end(arg);
	return (len);
}
