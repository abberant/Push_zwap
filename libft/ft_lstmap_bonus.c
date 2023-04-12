/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:23:16 by aanouari          #+#    #+#             */
/*   Updated: 2022/11/11 13:32:47 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*amp;

	new = NULL;
	amp = NULL;
	tmp = lst;
	if (!lst || !f || !del)
		return (NULL);
	while (tmp)
	{
		amp = ft_lstnew(f(tmp->content));
		if (!amp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, amp);
		tmp = tmp->next;
	}
	return (new);
}
