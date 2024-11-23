/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:44:39 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/11 15:04:12 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	arr_length(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

t_stack	*initialize_stack_a(char **args)
{
	t_stack	*s_a;
	int		count;

	s_a = malloc(sizeof(t_stack));
	s_a->top = -1;
	s_a->size = arr_length(args);
	count = s_a->size - 1;
	while (count >= 0)
	{
		s_a->top++;
		s_a->numbers[s_a->top] = ft_atoi(args[count]);
		count--;
	}
	return (s_a);
}

t_stack	*initialize_stack_b(void)
{
	t_stack	*s_b;

	s_b = malloc(sizeof(t_stack));
	s_b->top = -1;
	s_b->size = 0;
	return (s_b);
}

void	exit_without_errors(int argc, char **args, t_stack *s_a, t_stack *s_b)
{
	char	**ptr;

	if (argc == 2)
	{
		ptr = args;
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(args);
	}
	free(s_a);
	free(s_b);
	exit(0);
}

void	exit_with_errors(int argc, char **args)
{
	char	**ptr;

	if (argc == 2)
	{
		ptr = args;
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(args);
	}
	ft_printf("Error.  Usage: ./push_swap  INT INT INT (...)");
	ft_printf("  OR ALL INTs between quotation marks\n");
	ft_printf("Please, also remember not to exceed the INT limits\n");
	ft_printf("Please, do not repeat the numbers\n");
	exit(1);
}
