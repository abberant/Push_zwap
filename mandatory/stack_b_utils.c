/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:39:01 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/12 00:09:11 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack *nstack)
{
	t_stack	*current;
	int		i;

	i = -1;
	current = nstack;
	while (current)
	{
		current->position = ++i;
		current = current->next;
	}
}

void	set_target_position(t_ps *ps)
{
	t_stack	*current;
	int		t_pos;

	current = ps->stack_b;
	set_position(ps->stack_a);
	set_position(ps->stack_b);
	t_pos = 0;
	while (current)
	{
		t_pos = get_target(ps, current->final_rank,
				INT_MAX, t_pos);
		current->target_pos = t_pos;
		current = current->next;
	}
}

int	get_target(t_ps *ps, int b_rank, int near_rank, int t_pos)
{
	t_stack	*current;

	current = ps->stack_a;
	while (current)
	{
		if (current->final_rank > b_rank && current->final_rank < near_rank)
		{
			near_rank = current->final_rank;
			t_pos = current->position;
		}
		current = current->next;
	}
	if (near_rank != INT_MAX)
		return (t_pos);
	current = ps->stack_a;
	while (current)
	{
		if (current->final_rank < near_rank)
		{
			near_rank = current->final_rank;
			t_pos = current->position;
		}
		current = current->next;
	}
	return (t_pos);
}

void	get_costs(t_ps *ps)
{
	t_stack	*crt_a;
	t_stack	*crt_b;

	crt_a = ps->stack_a;
	crt_b = ps->stack_b;
	while (crt_b)
	{
		crt_b->cost_mvb = crt_b->position;
		if ((size_t)crt_b->position > ps->sizeof_b / 2)
			crt_b->cost_mvb = (ps->sizeof_b - crt_b->position) * -1;
		crt_b->cost_mva = crt_b->target_pos;
		if ((size_t)crt_b->target_pos > ps->sizeof_a / 2)
			crt_b->cost_mva = (ps->sizeof_a - crt_b->target_pos) * -1;
		crt_b = crt_b->next;
	}
}

void	make_moves(t_ps *ps)
{
	t_fm		ret;
	t_stack		*c;
	int			least;

	least = INT_MAX;
	c = ps->stack_b;
	while (c)
	{
		if (abs(c->cost_mva) + abs(c->cost_mvb) < abs(least))
		{
			least = abs(c->cost_mvb) + abs(c->cost_mva);
			ret.cost_stack_a = c->cost_mva;
			ret.cost_stack_b = c->cost_mvb;
		}
		c = c->next;
	}
	ret.ps = ps;
	execute_moves(ret);
}
