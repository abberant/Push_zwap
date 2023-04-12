/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:27:34 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/25 14:01:07 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long		num;

	num = n;
	if (num == -2147483648)
		ft_putstr("-2147483648");
	else if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putchar(num % 10 + 48);
	}
	if (num >= 0 && num <= 9)
		ft_putchar(num + 48);
}
