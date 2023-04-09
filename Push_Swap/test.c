/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:07:10 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/09 21:03:26 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t		i;
	t_ps	init;
	// t_stack	*tmp;

	i = 0;
	init.args_num = 0;
	if (argc == 2)
		arg_check(&init, argv[1]);
	if (!init.args_num)
		fill_args(&init, argc, argv);
	if (!initialize_stacks(&init))
		return (0);
	if (sorted_stack(init.stack_a))
		ft_kill("Stack is sorted !");
	setting_ranks(&init, init.sizeof_a);
	push_swap(&init);
	while (i < init.sizeof_a || i < init.sizeof_b)
	{
		if (!init.stack_a)
			dprintf(2, "Empty,				");
		else
		{
			dprintf(2, "Content of stack_a[%zu] is : [%d],	", i, init.stack_a->content);
			init.stack_a = init.stack_a->next;
		}
		if (!init.stack_b)
			dprintf(2, "Empty\n");
		else
		{
			dprintf(2, "Content of stack_b[%zu] is : [%d]\n", i, init.stack_b->content);
			init.stack_b = init.stack_b->next;
		}
		i++;
	}
	return (0);
}
