/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:02:13 by aanouari          #+#    #+#             */
/*   Updated: 2022/11/05 12:57:25 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_allocate(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n > 0)
	{
		while (n)
		{
			count++;
			n /= 10;
		}
	}
	return (count + 1);
}

static char	*ft_strrev(char *s)
{
	int		i;
	int		count;
	char	tmp;

	i = 0;
	count = 0;
	while (s[count])
		count++;
	count--;
	while (i < count)
	{
		tmp = s[i];
		s[i] = s[count];
		s[count] = tmp;
		i++;
		count--;
	}
	return (s);
}

static void	ft_negative(char *s, int n, int *i)
{
	if (n < 0)
	{
		s[*i++] = '-';
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		a;
	char	*s;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		s = ft_calloc(ft_allocate(n), sizeof(char));
	if (!s)
		return (NULL);
	a = n;
	if (n < 0)
		n *= -1;
	while (n)
	{
		s[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	ft_negative(s, a, &i);
	return (ft_strrev(s));
}
