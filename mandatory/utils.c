/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:43:51 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/14 18:28:03 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_check(t_ps *init, char *s)
{
	int	i;

	i = 0;
	init->n_argv = ft_split(s, ' ');
	if (!init->n_argv)
		ft_kill("Error");
	while (init->n_argv[i])
		i++;
	init->args_num = 1;
	init->n_argc = i;
}

void	fill_args(t_ps *init, int argc, char **argv)
{
	init->n_argc = argc - 1;
	init->n_argv = argv + 1;
}

int	duplicate_args(int argc, char **argv)
{
	int	*tab;
	int	i;
	int	j;
	int	found;

	found = 1;
	tab = (int *)malloc(argc * sizeof(int));
	if (!tab)
		return (1);
	i = -1;
	while (++i < argc)
		tab[i] = ft_atoi(argv[i]);
	i = -1;
	while (++i < argc && found)
	{
		j = i;
		while (++j < argc && found)
			if (tab[i] == tab[j])
				found = 0;
	}
	free(tab);
	return (!found);
}

void	setting_ranks(t_ps *ps, size_t size)
{
	t_stack	*current;
	t_stack	*highest;
	int		stocked;

	while (size > 0)
	{
		highest = NULL;
		stocked = INT_MIN;
		current = ps->stack_a;
		while (current)
		{
			if (current->content == INT_MIN && current->final_rank == DEFAULT)
				current->final_rank = 1;
			if (current->content > stocked && current->final_rank == DEFAULT)
			{
				stocked = current->content;
				highest = current;
			}
			current = current->next;
		}
		if (highest)
			highest->final_rank = size;
		size--;
	}
}

int	initialize_stacks(t_ps *ps)
{
	t_stack	*new;
	int		i;

	i = -1;
	if (!ps->n_argc || ps->n_argc == 1)
		return (0);
	if (duplicate_args(ps->n_argc, ps->n_argv))
		ft_kill("Error");
	ps->stack_a = NULL;
	i = 0;
	while (i < ps->n_argc)
	{
		new = addon_stack(ft_atoi(ps->n_argv[i]));
		if (!new)
			return (clear_stack(&ps->stack_a));
		addback_stack(&ps->stack_a, new);
		i++;
	}
	ps->stack_b = NULL;
	ps->sizeof_a = ps->n_argc;
	ps->sizeof_b = 0;
	return (1);
}
