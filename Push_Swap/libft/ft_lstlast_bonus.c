/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:51:40 by aanouari          #+#    #+#             */
/*   Updated: 2022/11/05 12:53:47 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (!lst)
		return (NULL);
	tmp = lst;
	while (i < ft_lstsize(lst))
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
