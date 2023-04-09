/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:20:37 by aanouari          #+#    #+#             */
/*   Updated: 2023/02/15 16:43:17 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if ((dstsize == 0 && !dst) || dstsize == 0)
		return (ft_strlen(src));
	j = ft_strlen(src);
	k = ft_strlen(dst);
	while (src[i] && (i + k < dstsize - 1))
	{
		dst[i + k] = src[i];
		i++;
	}
	dst[i + k] = '\0';
	if (k < dstsize)
		return (j + k);
	return (j + dstsize);
}
