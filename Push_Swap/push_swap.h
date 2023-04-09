/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:07:38 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/09 18:37:43 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

# define DEFAULT 0

typedef struct		s_stack
{
	int				content;
	int				position;
	int				target_pos;
	int				cost_mva;
	int				cost_mvb;
	int				final_rank;
	struct s_stack	*next;
}					t_stack;

typedef struct	s_track
{
	t_stack		*head;
	t_stack		*current;
}				t_track;

typedef struct	s_ps
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	sizeof_a;
	size_t	sizeof_b;
	int		args_num;
	int		n_argc;
	char	**n_argv;
}	t_ps;

typedef struct	s_fm
{
	t_ps	*ps;
	int		cost_stack_a;
	int		cost_stack_b;
}				t_fm;

/*----> RANDOM UTILS <----*/

void	arg_check(t_ps *init, char *s);
void	fill_args(t_ps *init, int argc, char **argv);
int		check_int_type(char	*str);
int		duplicate_args(int argc, char **argv);
void	ft_kill(char *reason);
int		get_highest_rank(t_stack *stack);

/*----> LINKED LIST UTILS <----*/

t_stack	*duplicate_stack(t_stack nstack);
t_stack	*addon_stack(int content);
t_stack	*laststack(t_stack *nstack);
int		clear_stack(t_stack **nstack);
void	addfront_stack(t_stack **nstack, t_stack *s_new);
void	addback_stack(t_stack **nstack, t_stack *s_new);
int		sorted_stack(t_stack *nstack);
t_stack	*prelast(t_stack *nstack);

/*----> SETTING RANKS <----*/

void	setting_ranks(t_ps *ps, size_t size);

/*----> STACK INITIALIZATION <----*/

int	initialize_stacks(t_ps *ps);

/*----> PUSH SWAP OPERATIONS <----*/

int	swap_a(t_ps *ps, int index);
int	swap_b(t_ps *ps, int index);
int	swap_ab(t_ps *ps, int index);
int	push_a(t_ps *ps, int index);
int	push_b(t_ps *ps, int index);
int	rotate_a(t_ps *ps, int index);
int	rotate_b(t_ps *ps, int index);
int	rotate_ab(t_ps *ps, int index);
int	reverse_rotate_a(t_ps *ps, int index);
int	reverse_rotate_b(t_ps *ps, int index);
int	reverse_rotate_ab(t_ps *ps, int index);

/*----> ALGORITHM <----*/

void	push_swap(t_ps *ps);
void	sort_three(t_ps *ps);
void	push_to_b(t_ps *ps, size_t size);
void	sort_full_stack(t_ps *ps);
void	set_position(t_stack *nstack);
void	set_target_position(t_ps *ps);
int		get_target(t_ps *ps, int b_rank, int near_rank, int t_pos);
void	get_costs(t_ps *ps);
void	make_moves(t_ps *ps);
void	loop_rotate_a(t_ps *ps, int *cost_stack_a);
void	loop_rotate_b(t_ps *ps, int *cost_stack_b);
void	get_lp_by_ranking(t_stack *stack, int *lp);
void	rotate_stack(t_ps *ps, t_stack *stack, size_t size);
void	execute_moves(t_fm ret);


#endif