/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 02:24:45 by aanouari          #+#    #+#             */
/*   Updated: 2023/02/15 16:43:05 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	precheck(char *s1, char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j] && s1[i])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

static int	postcheck(char *s1, char *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] && s1[i])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i--;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	pre;
	size_t	post;
	char	*ptr;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	pre = precheck(s1, set);
	post = postcheck(s1, set);
	if (pre == ft_strlen(s1) || post == 0)
		return (ft_strdup("\0"));
	ptr = (char *)malloc(((post - pre) + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (pre <= post)
		ptr[i++] = s1[pre++];
	ptr[i] = '\0';
	return (ptr);
}
