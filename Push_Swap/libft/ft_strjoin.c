/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:18:21 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/12 04:22:31 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = 0;
	if (!s1)
		s1 = (char *) ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (0);
	s = (char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s)
		return (0);
	if (s1)
		while (s1[++i])
			s[i] = s1[i];
	while (s2[j])
		s[i++] = s2[j++];
	free(s1);
	return (s);
}
