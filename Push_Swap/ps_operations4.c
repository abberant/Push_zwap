/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:13:19 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/07 17:35:40 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*prelast(t_stack *nstack)
{
	t_stack	*tmp;

	if (!nstack)
		return (NULL);
	if (!nstack->next)
		return (nstack);
	tmp = nstack;
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

int	reverse_rotate_a(t_ps *ps, int index)
{
	t_stack	*last;

	if (ps->sizeof_a < 2)
		return (0);
	last = laststack(ps->stack_a);
	addfront_stack(&ps->stack_a, duplicate_stack(*(last)));
	prelast(ps->stack_a)->next = NULL;
	free (last);
	if (index)
		ft_putstr_fd("rra\n", 1);
	return (1);
}

int	reverse_rotate_b(t_ps *ps, int index)
{
	t_stack	*last;

	if (ps->sizeof_b < 2)
		return (0);
	last = laststack(ps->stack_b);
	addfront_stack(&ps->stack_b, duplicate_stack(*(last)));
	prelast(ps->stack_b)->next = NULL;
	free (last);
	if (index)
		ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	reverse_rotate_ab(t_ps *ps, int index)
{
	return (reverse_rotate_a(ps, index) + reverse_rotate_b(ps, index));
}