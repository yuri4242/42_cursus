/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:43:12 by yikebata          #+#    #+#             */
/*   Updated: 2025/12/01 09:50:44 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_idx(t_stack *stack)
{
	int		max;
	t_node	*cur;

	if (!stack || !stack->top)
		return (-1);
	max = stack->top->idx;
	cur = stack->top->next;
	while (cur != stack->top)
	{
		if (cur->idx > max)
			max = cur->idx;
		cur = cur->next;
	}
	return (max);
}

void	three_sort(t_stack *stack_a)
{
	int	max_idx;

	max_idx = get_max_idx(stack_a);
	if (max_idx == -1)
		return ;
	if (stack_a->top->idx == max_idx)
		ra(stack_a, 1);
	else if (stack_a->top->next->idx == max_idx)
		rra(stack_a, 1);
	if (stack_a->top->idx > stack_a->top->next->idx)
		sa(stack_a, 1);
}
