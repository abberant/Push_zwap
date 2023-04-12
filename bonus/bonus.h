/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:39:06 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/12 00:01:20 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../mandatory/push_swap.h"

void	array_org(int (*behaviour[11])(t_ps *ps, int index),
			char *operation[11]);
void	ft_checker(t_ps *ps, char *pivot);
void	check_sorting(t_ps *ps);

#endif