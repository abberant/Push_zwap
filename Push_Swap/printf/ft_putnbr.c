/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:27:34 by aanouari          #+#    #+#             */
/*   Updated: 2022/11/24 14:27:35 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	size_t		len;
	long		num;

	len = 0;
	num = n;
	if (num == -2147483648)
		len += ft_putstr("-2147483648");
	else if (num < 0)
	{
		len += ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
	{
		len += ft_putnbr(num / 10);
		len += ft_putchar(num % 10 + 48);
	}
	if (num >= 0 && num <= 9)
		len += ft_putchar(num + 48);
	return (len);
}
