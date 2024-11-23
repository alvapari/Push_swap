/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:41:01 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/10 18:41:11 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	r_rotate(t_stack *stack)
{
	int	save;
	int	i;

	save = stack->numbers[0];
	i = 0;
	while (i < stack->top)
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[stack->top] = save;
}

void	rra(t_stack *s_a)
{
	r_rotate(s_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *s_b)
{
	r_rotate(s_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *s_a, t_stack *s_b)
{
	r_rotate(s_a);
	r_rotate(s_b);
	ft_printf("rrs\n");
}
