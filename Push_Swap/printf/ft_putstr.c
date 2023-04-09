/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:27:20 by aanouari          #+#    #+#             */
/*   Updated: 2022/11/25 15:56:51 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*str)
		len += ft_putchar(*(str++));
	return (len);
}
