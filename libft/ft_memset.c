/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:35:01 by aanouari          #+#    #+#             */
/*   Updated: 2022/10/27 21:19:38 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cpy;
	size_t			i;

	cpy = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		cpy[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
