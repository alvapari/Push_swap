/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:37:58 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/10 18:38:13 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	dst->top++;
	dst->numbers[dst->top] = src->numbers[src->top];
	src->top--;
}

void	pa(t_stack *s_a, t_stack *s_b)
{
	push(s_b, s_a);
	ft_printf("pa\n");
}

void	pb(t_stack *s_a, t_stack *s_b)
{
	push(s_a, s_b);
	ft_printf("pb\n");
}
