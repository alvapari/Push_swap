/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:34:50 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/11 13:43:20 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	still_chunk(t_stack *s_a, int chunk_start, int chunk_end)
{
	int	cnt;

	cnt = 0;
	while (cnt <= s_a->top)
	{
		if (s_a->numbers[cnt] >= chunk_start && s_a->numbers[cnt] <= chunk_end)
			return (true);
		cnt++;
	}
	return (false);
}

static int	cost_from_top(t_stack *s_a, int chunk_start, int chunk_end)
{
	int	cnt;
	int	count2;

	cnt = s_a->top;
	count2 = 0;
	while (cnt >= 0)
	{
		if (s_a->numbers[cnt] >= chunk_start && s_a->numbers[cnt] <= chunk_end)
			return (count2);
		cnt--;
		count2++;
	}
	return (count2);
}

static int	cost_from_bottom(t_stack *s_a, int chunk_start, int chunk_end)
{
	int	cnt;

	cnt = 0;
	while (cnt <= s_a->top)
	{
		if (s_a->numbers[cnt] >= chunk_start && s_a->numbers[cnt] <= chunk_end)
			return (cnt);
		cnt++;
	}
	return (cnt);
}

void	chunksrt(t_stack *s_a, t_stack *s_b, int chunk_start, int chunk_end)
{
	int	top;
	int	min;

	while (still_chunk(s_a, chunk_start, chunk_end))
	{
		top = cost_from_top(s_a, chunk_start, chunk_end);
		min = cost_from_bottom(s_a, chunk_start, chunk_end);
		if (top < min)
		{
			top = s_a->top - top;
			while (top++ < s_a->top)
				ra(s_a);
		}
		else
		{
			while (min-- >= 0)
				rra(s_a);
		}
		pb(s_a, s_b);
	}
}
