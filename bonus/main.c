/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:39:04 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/12 00:02:11 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int argc, char **argv)
{
	t_ps	init;
	char	*pivot;

	init.args_num = 0;
	if (argc == 2)
		arg_check(&init, argv[1]);
	if (!init.args_num)
		fill_args(&init, argc, argv);
	if (!initialize_stacks(&init))
		return (0);
	while (1)
	{
		pivot = get_next_line(0);
		if (!pivot || *pivot == '\n')
		{
			free(pivot);
			check_sorting(&init);
			exit(0);
		}
		ft_checker(&init, pivot);
		free(pivot);
	}
}
