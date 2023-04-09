/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:26:11 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/09 18:37:56 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *ps)
{
	int	highest;

	highest = get_highest_rank(ps->stack_a);
	if (ps->stack_a->final_rank == highest)
		rotate_a(ps, 1);
	else if (ps->stack_a->next->final_rank == highest)
		reverse_rotate_a(ps, 1);
	if (ps->stack_a->final_rank > ps->stack_a->next->final_rank)
		swap_a(ps, 1);
}

void	push_to_b(t_ps *ps, size_t size)
{
	int	i;
	size_t	pushed2b;

	i = 0;
	pushed2b = 0;
	while (size > 6 && (size_t)i < size && pushed2b < size / 2)
	{
		if ((size_t)ps->stack_a->final_rank <= size / 2)
			pushed2b += push_b(ps , 1);
		else
			rotate_a(ps, 1);
		i++;
	}
	while (size - pushed2b > 3)
		pushed2b += push_b(ps, 1);
	// dprintf(2, "NEXT\n");
}

void	get_lp_by_ranking(t_stack *stack, int *lp)
{
	t_stack	*current;
	int		least_rank;

	least_rank = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->final_rank < least_rank)
		{
			*lp = current->position;
			least_rank = current->final_rank;
		}
		current = current->next;
	}
}

void	sort_full_stack(t_ps *ps)
{
	push_to_b(ps, ps->sizeof_a);
	sort_three(ps);
	while (ps->stack_b)
	{
		set_target_position(ps);
		get_costs(ps);
		make_moves(ps);
	}
	if (!sorted_stack(ps->stack_a))
		rotate_stack(ps, ps->stack_a, ps->sizeof_a);
}

void	push_swap(t_ps *ps)
{
	if (ps->sizeof_a == 2)
		swap_a(ps, 1);
	else if (ps->sizeof_a == 3)
		sort_three(ps);
	else
		sort_full_stack(ps);
}
