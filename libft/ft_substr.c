/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:22:37 by aanouari          #+#    #+#             */
/*   Updated: 2023/02/15 16:43:05 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	if (len > ft_strlen(s))
		ptr = (char *)malloc(ft_strlen(s) + 1);
	else
		ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (s[i] && i < len)
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}
