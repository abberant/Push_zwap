/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:39:35 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/12 00:04:53 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_ps *ps, int index)
{
	if (ps->sizeof_a < 2)
		return (0);
	addfront_stack(&ps->stack_a, duplicate_stack(*(ps->stack_a->next)));
	free(ps->stack_a->next->next);
	ps->stack_a->next->next = ps->stack_a->next->next->next;
	if (index)
		ft_putstr_fd("sa\n", 1);
	return (1);
}

int	swap_b(t_ps *ps, int index)
{
	if (ps->sizeof_b < 2)
		return (0);
	addfront_stack(&ps->stack_b, duplicate_stack(*(ps->stack_b->next)));
	free(ps->stack_b->next->next);
	ps->stack_b->next->next = ps->stack_b->next->next->next;
	if (index)
		ft_putstr_fd("sb\n", 1);
	return (1);
}

int	swap_ab(t_ps *ps, int index)
{
	return (swap_a(ps, index) + swap_b(ps, index));
}
