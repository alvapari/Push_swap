/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:35:54 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/10 20:39:04 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*s_a;
	t_stack	*s_b;
	char	**args;

	if (argc <= 1)
	{
		args = NULL;
		return (0);
	}
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	check_arguments(argc, args);
	s_a = initialize_stack_a(args);
	s_b = initialize_stack_b();
	if (s_a->size <= 6)
		smallsort(s_a, s_b);
	else
		supersort(s_a, s_b);
	exit_without_errors(argc, args, s_a, s_b);
	return (0);
}
