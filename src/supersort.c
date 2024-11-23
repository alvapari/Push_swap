/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:48:28 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/11 13:15:00 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	min_position(t_stack *s_a)
{
	int	count;
	int	aux;

	count = s_a->top - 1;
	aux = s_a->top;
	while (count >= 0)
	{
		if (s_a->numbers[count] < s_a->numbers[aux])
			aux = count;
		count--;
	}
	return (aux);
}

static int	max_position(t_stack *stack)
{
	int	count;
	int	aux;

	count = stack->top - 1;
	aux = stack->top;
	while (count >= 0)
	{
		if (stack->numbers[count] > stack->numbers[aux])
			aux = count;
		count--;
	}
	return (aux);
}

static void	nbrstoa(t_stack *s_a, t_stack *s_b)
{
	int	top_back;

	while (s_b->top >= 0)
	{
		top_back = max_position(s_b);
		if (top_back > s_b->top / 2)
		{
			while (top_back < s_b->top)
			{
				rb(s_b);
				top_back++;
			}
		}
		else
		{
			while (top_back >= 0)
			{
				rrb(s_b);
				top_back--;
			}
		}
		pa(s_a, s_b);
	}
}

void	supersort(t_stack *s_a, t_stack *s_b)
{
	int	chunk_nbr;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	if (s_a->size <= 100)
		chunk_nbr = 5;
	else
		chunk_nbr = 11;
	chunk_size = s_a->numbers[max_position(s_a)] / chunk_nbr;
	chunk_start = s_a->numbers[min_position(s_a)];
	while (chunk_start < s_a->numbers[max_position(s_a)])
	{
		chunk_end = chunk_start + chunk_size;
		chunksrt(s_a, s_b, chunk_start, chunk_end);
		chunk_start += chunk_size;
	}
	nbrstoa(s_a, s_b);
}
