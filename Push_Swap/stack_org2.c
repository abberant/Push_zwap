/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_org2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 03:20:05 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/08 17:58:50 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*duplicate_stack(t_stack nstack)
{
	t_stack	*tab;

	tab = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!tab)
		return (NULL);
	tab->content = nstack.content;
	tab->position = nstack.position;
	tab->target_pos = nstack.target_pos;
	tab->final_rank = nstack.final_rank;
	tab->cost_mva = nstack.cost_mva;
	tab->cost_mvb = nstack.cost_mvb;
	tab->next = NULL;
	return (tab);
}

int	sorted_stack(t_stack *nstack)
{
	t_stack	*current;

	current = nstack;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
