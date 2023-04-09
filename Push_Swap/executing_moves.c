/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:45:36 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/09 18:17:21 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_highest_rank(t_stack *stack)
{
	t_stack	*current;
	int		highest;

	current = stack;
	highest = current->final_rank;
	while (current)
	{
		if (current->final_rank > highest)
			highest = current->final_rank;
		current = current->next;
	}
	return (highest);
}

void	loop_rotate_a(t_ps *ps, int *cost_stack_a)
{
	while (*(cost_stack_a))
	{
		if (*(cost_stack_a) > 0)
			*(cost_stack_a) -= rotate_a(ps, 1);

		else if (*(cost_stack_a) < 0)
			*(cost_stack_a) += reverse_rotate_a(ps, 1);
	}
}

void	loop_rotate_b(t_ps *ps, int *cost_stack_b)
{
	while (*(cost_stack_b))
	{
		if (*(cost_stack_b) > 0)
			*(cost_stack_b) -= rotate_b(ps, 1);
		else if (*(cost_stack_b) < 0)
			*(cost_stack_b) += reverse_rotate_b(ps, 1);
	}
}

void	execute_moves(t_fm ret)
{
	if (ret.cost_stack_a < 0 && ret.cost_stack_b < 0)
	{
		while (ret.cost_stack_a < 0 && ret.cost_stack_b < 0)
		{
			reverse_rotate_ab(ret.ps, 1);
			(ret.cost_stack_a)++;
			(ret.cost_stack_b)++;
		}
	}
	else if (ret.cost_stack_a > 0 && ret.cost_stack_b > 0)
	{
		while (ret.cost_stack_a > 0 && ret.cost_stack_b > 0)
		{
			rotate_ab(ret.ps, 1);
			(ret.cost_stack_a)--;
			(ret.cost_stack_b)--;
		}
	}
	// dprintf(2, "MOVE\n");
	// dprintf(2, "cost_stack_a is [%d]\n", ret.cost_stack_a);
	// dprintf(2, "cost_stack_b is [%d]\n", ret.cost_stack_b);
	loop_rotate_a(ret.ps, &ret.cost_stack_a);
	loop_rotate_b(ret.ps, &ret.cost_stack_b);
	push_a(ret.ps, 1);
}

void	rotate_stack(t_ps *ps, t_stack *stack, size_t size)
{
	int	least_pos; 

	set_position(stack);
	least_pos = stack->position;
	get_lp_by_ranking(stack, &least_pos);
	if ((size_t)least_pos > size / 2)
		while ((size_t)least_pos < size)
			least_pos += reverse_rotate_a(ps, 1);
	else
		while (least_pos)
			least_pos -= rotate_a(ps, 1);
}