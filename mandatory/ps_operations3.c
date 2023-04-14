/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:05:40 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/12 21:20:04 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_ps *ps, int index)
{
	t_stack	*tmp;

	if (ps->sizeof_a < 2)
		return (0);
	addback_stack(&ps->stack_a, duplicate_stack(*(ps->stack_a)));
	tmp = ps->stack_a->next;
	free(ps->stack_a);
	ps->stack_a = tmp;
	if (index)
		ft_putstr_fd("ra\n", 1);
	return (1);
}

int	rotate_b(t_ps *ps, int index)
{
	t_stack	*tmp;

	if (ps->sizeof_b < 2)
		return (0);
	addback_stack(&ps->stack_b, duplicate_stack(*(ps->stack_b)));
	tmp = ps->stack_b->next;
	free(ps->stack_b);
	ps->stack_b = tmp;
	if (index)
		ft_putstr_fd("rb\n", 1);
	return (1);
}

int	rotate_ab(t_ps *ps, int index)
{
	return (rotate_a(ps, index) + rotate_b(ps, index));
}
