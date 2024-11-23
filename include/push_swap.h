/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:19:21 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/11 10:45:38 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int	numbers[1024];
	int	top;
	int	size;
}	t_stack;

void	sa(t_stack *s_a);
void	sb(t_stack *s_b);
void	ss(t_stack *s_a, t_stack *s_b);

void	rra(t_stack *s_a);
void	rrb(t_stack *s_b);
void	rrr(t_stack *s_a, t_stack *s_b);

void	ra(t_stack *s_a);
void	rb(t_stack *s_b);
void	rr(t_stack *s_a, t_stack *s_b);

void	pa(t_stack *s_a, t_stack *s_b);
void	pb(t_stack *s_a, t_stack *s_b);
void	push(t_stack *src, t_stack *dst);

void	smallsort(t_stack *s_a, t_stack *s_b);

t_stack	*initialize_stack_a(char **args);
t_stack	*initialize_stack_b(void);
void	exit_with_errors(int argc, char **args);
void	exit_without_errors(int argc, char **args, t_stack *s_a, t_stack *s_b);

void	check_arguments(int argc, char **args);

void	supersort(t_stack *s_a, t_stack *s_b);

void	chunksrt(t_stack *s_a, t_stack *s_b, int chunk_start, int chunk_end);
#endif