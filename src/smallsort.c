/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:42:33 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/11 12:39:47 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort3(t_stack *s_a)
{
	int	*nums;

	nums = s_a->numbers;
	if (nums[2] > nums[1] && nums[1] > nums[0] && nums[0] < nums[2])
	{
		sa(s_a);
		rra(s_a);
	}
	else if (nums[2] > nums[1] && nums[1] < nums[0] && nums[0] < nums[2])
		ra(s_a);
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] > nums[2])
		sa(s_a);
	else if (nums[0] > nums[2] && nums[2] < nums[1] && nums[0] < nums[1])
	{
		sa(s_a);
		ra(s_a);
	}
	else if (nums[0] < nums[2] && nums[2] < nums[1] && nums[1] > nums[0])
		rra(s_a);
}

void	smallest_tob(t_stack *s_a, t_stack *s_b)
{
	int	count;
	int	aux_pos;

	count = s_a->top - 1;
	aux_pos = s_a->top;
	while (count >= 0)
	{
		if (s_a->numbers[count] < s_a->numbers[aux_pos])
			aux_pos = count;
		count--;
	}
	while (aux_pos < s_a->top)
	{
		ra(s_a);
		aux_pos++;
	}
	pb(s_a, s_b);
}

void	sort5(t_stack *s_a, t_stack *s_b)
{
	smallest_tob(s_a, s_b);
	smallest_tob(s_a, s_b);
	sort3(s_a);
	pa(s_a, s_b);
	pa(s_a, s_b);
}

void	smallsort(t_stack *s_a, t_stack *s_b)
{
	if (s_a->size == 1)
		return ;
	else if (s_a->size == 2)
	{
		if (s_a->numbers[s_a->top] > s_a->numbers[s_a->top - 1])
			sa(s_a);
	}
	else if (s_a->size == 3)
		sort3(s_a);
	else if (s_a->size == 4)
	{
		smallest_tob(s_a, s_b);
		sort3(s_a);
		pa(s_a, s_b);
	}
	else if (s_a->size == 5)
		sort5(s_a, s_b);
	else
	{
		smallest_tob(s_a, s_b);
		sort5(s_a, s_b);
		pa(s_a, s_b);
	}
}
