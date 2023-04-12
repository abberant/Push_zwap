/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:06:04 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/12 00:04:56 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_ps *ps, int index)
{
	t_stack	*hold;

	if (ps->sizeof_b < 1)
		return (0);
	hold = ps->stack_b->next;
	addfront_stack(&ps->stack_a, ps->stack_b);
	ps->stack_b = hold;
	ps->sizeof_a++;
	ps->sizeof_b--;
	if (index)
		ft_putstr_fd("pa\n", 1);
	return (1);
}

int	push_b(t_ps *ps, int index)
{
	t_stack	*hold;

	if (ps->sizeof_a < 1)
		return (0);
	hold = ps->stack_a->next;
	addfront_stack(&ps->stack_b, ps->stack_a);
	ps->stack_a = hold;
	ps->sizeof_b++;
	ps->sizeof_a--;
	if (index)
		ft_putstr_fd("pb\n", 1);
	return (1);
}
