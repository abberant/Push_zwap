/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:20:07 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/12 04:22:08 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return (1);
	while (i < len && haystack[i])
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j] && k < len)
		{
			if (needle[j + 1] == '\0')
				return (1);
			j++;
			k++;
		}
		i++;
	}
	return (0);
}
