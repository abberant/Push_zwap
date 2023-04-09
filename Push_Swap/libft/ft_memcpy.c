/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:30:11 by aanouari          #+#    #+#             */
/*   Updated: 2023/02/15 16:44:06 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t			i;
	unsigned char	*copy;
	unsigned char	*paste;

	copy = (unsigned char *)dst;
	paste = (unsigned char *)src;
	if (src == dst)
		return (dst);
	i = 0;
	while ((dst || src) && i < n)
	{
		copy[i] = paste[i];
		i++;
	}
	return (dst);
}
