/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:28:58 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/11 19:58:56 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	array_org(int (*behaviour[11])(t_ps *ps, int index),
		char *operation[11])
{
	behaviour[0] = &swap_a;
	behaviour[1] = &swap_b;
	behaviour[2] = &swap_ab;
	behaviour[3] = &push_a;
	behaviour[4] = &push_b;
	behaviour[5] = &rotate_a;
	behaviour[6] = &rotate_b;
	behaviour[7] = &rotate_ab;
	behaviour[8] = &reverse_rotate_a;
	behaviour[9] = &reverse_rotate_b;
	behaviour[10] = &reverse_rotate_ab;
	operation[0] = "sa";
	operation[1] = "sb";
	operation[2] = "ss";
	operation[3] = "pa";
	operation[4] = "pb";
	operation[5] = "ra";
	operation[6] = "rb";
	operation[7] = "rr";
	operation[8] = "rra";
	operation[9] = "rrb";
	operation[10] = "rrr";
}

void	ft_checker(t_ps *ps, char *pivot)
{
	int		(*behaviour[11])(t_ps *ps, int index);
	char	*operation[11];
	int		check;

	check = 0;
	array_org(behaviour, operation);
	while (check < 11)
	{
		if (!ft_strncmp(operation[check], pivot, ft_strlen(operation[check])))
			if (pivot[ft_strlen(operation[check])] == '\n')
				break ;
		check++;
	}
	behaviour[check](ps, 0);
}

void	check_sorting(t_ps *ps)
{
	t_stack	*current;

	if (ps->sizeof_b)
	{
		ft_putstr_fd("KO\n", 2);
		exit(0);
	}
	current = ps->stack_a;
	if (sorted_stack(current))
	{
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
}
