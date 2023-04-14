/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:07:10 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/14 18:32:53 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_ps *ps)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!ps->stack_a)
		return ;
	current = ps->stack_a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	ps->stack_a = NULL;
}

int	main(int argc, char **argv)
{
	size_t	i;
	t_ps	init;

	i = 0;
	init.args_num = 0;
	if (argc == 2)
		arg_check(&init, argv[1]);
	if (!init.args_num)
		fill_args(&init, argc, argv);
	if (!initialize_stacks(&init))
		return (0);
	if (sorted_stack(init.stack_a))
		return (0);
	setting_ranks(&init, init.sizeof_a);
	push_swap(&init);
	free_stack(&init);
	return (0);
}
