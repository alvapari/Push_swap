/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:40:16 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/11 13:50:14 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack *stack)
{
	int	save;
	int	cnt;

	save = stack->numbers[stack->top];
	cnt = stack->top;
	while (cnt > 0)
	{
		stack->numbers[cnt] = stack->numbers[cnt - 1];
		cnt--;
	}
	stack->numbers[0] = save;
}

void	ra(t_stack *s_a)
{
	rotate(s_a);
	ft_printf("ra\n");
}

void	rb(t_stack *s_b)
{
	rotate(s_b);
	ft_printf("rb\n");
}

void	rr(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a);
	rotate(s_b);
	ft_printf("rs\n");
}
