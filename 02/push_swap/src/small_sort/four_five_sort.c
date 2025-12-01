/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_five_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:23:24 by yikebata          #+#    #+#             */
/*   Updated: 2025/12/01 10:24:10 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(t_stack *stack, int min_idx)
{
	int		pos;
	t_node	*cur;

	pos = 0;
	cur = stack->top;
	while (cur)
	{
		if (cur->idx == min_idx)
			break ;
		pos++;
		cur = cur->next;
	}
	if (pos <= stack->size / 2)
	{
		while (stack->top->idx != min_idx)
			ra(stack, 1);
	}
	else
	{
		while (stack->top->idx != min_idx)
			rra(stack, 1);
	}
}

void	four_five_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_idx;

	min_idx = 0;
	while (stack_a->size > 3)
	{
		move_min_to_top(stack_a, min_idx);
		pb(stack_a, stack_b, 1);
		min_idx++;
	}
	three_sort(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, 1);
}
