/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:50:27 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/10 18:50:38 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack *stack)
{
	int	save;

	save = stack->numbers[stack->top];
	stack->numbers[stack->top] = stack->numbers[stack->top - 1];
	stack->numbers[stack->top - 1] = save;
}

void	sa(t_stack *s_a)
{
	swap(s_a);
	ft_printf("sa\n");
}

void	sb(t_stack *s_b)
{
	swap(s_b);
	ft_printf("sb\n");
}

void	ss(t_stack *s_a, t_stack *s_b)
{
	swap(s_a);
	swap(s_b);
	ft_printf("ss\n");
}
