/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_org.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:08:25 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/12 00:09:42 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*addon_stack(int content)
{
	t_stack	*nstack;

	nstack = ft_calloc(sizeof(t_stack), 1);
	if (!nstack)
		return (0);
	nstack->content = content;
	nstack->cost_mva = DEFAULT;
	nstack->cost_mvb = DEFAULT;
	nstack->position = DEFAULT;
	nstack->target_pos = DEFAULT;
	nstack->final_rank = DEFAULT;
	nstack->next = NULL;
	return (nstack);
}

t_stack	*laststack(t_stack *nstack)
{
	t_stack	*turn;

	if (!nstack)
		return (NULL);
	turn = nstack;
	while (turn->next)
	{
		turn = turn->next;
	}
	return (turn);
}

int	clear_stack(t_stack **nstack)
{
	t_stack	*current;
	t_stack	*next;

	if (!nstack)
		return (1);
	current = (*nstack);
	next = (*nstack);
	while (current)
	{
		next = next->next;
		free(current);
		current = next;
	}
	*nstack = NULL;
	return (1);
}

void	addfront_stack(t_stack **nstack, t_stack *s_new)
{
	if (!s_new)
		return ;
	if (!nstack)
	{
		*nstack = s_new;
		return ;
	}
	s_new->next = (*nstack);
	(*nstack) = s_new;
}

void	addback_stack(t_stack **nstack, t_stack *s_new)
{
	t_stack	*current;

	if (!nstack || !s_new)
		return ;
	current = (*nstack);
	if (!current)
	{
		*nstack = s_new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = s_new;
}
