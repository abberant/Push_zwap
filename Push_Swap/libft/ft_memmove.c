/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:18:45 by aanouari          #+#    #+#             */
/*   Updated: 2023/02/15 16:44:06 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*copy;
	unsigned char	*paste;

	copy = (unsigned char *)src;
	paste = (unsigned char *)dst;
	if (src == dst)
		return (dst);
	if (!dst && ! src)
		return (NULL);
	if (paste > copy)
	{
		while (len)
		{
			paste[len - 1] = copy[len - 1];
			len--;
		}
	}
	else
	{
		ft_memcpy(paste, copy, len);
	}
	return ((void *)paste);
}
