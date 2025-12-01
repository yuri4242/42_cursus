/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:19:08 by yikebata          #+#    #+#             */
/*   Updated: 2025/12/01 16:38:55 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_cheapest(t_stack *stack)
{
	int		tmp_cheapest_val;
	t_node	*tmp_cheapest;
	t_node	*cur;

	if (!stack || !stack->top)
		return (NULL);
	tmp_cheapest_val = INT_MAX;
	tmp_cheapest = NULL;
	cur = stack->top;
	while (cur)
	{
		cur->cheapest_flag = false;
		if (cur->optimal_cost < tmp_cheapest_val)
		{
			tmp_cheapest_val = cur->optimal_cost;
			tmp_cheapest = cur;
		}
		cur = cur->next;
		if (cur == stack->top)
			break ;
	}
	if (tmp_cheapest)
		tmp_cheapest->cheapest_flag = true;
	return (tmp_cheapest);
}

void	additional_rotate(t_stack *stack, t_node *expected_top, char stack_type)
{
	while (stack->top != expected_top)
	{
		if (stack_type == 'a')
		{
			if (expected_top->above_median_flag)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_type == 'b')
		{
			if (expected_top->above_median_flag)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

t_node	*find_min(t_stack *stack)
{
	t_node	*cur;
	t_node	*min;
	int		min_idx;

	min = NULL;
	min_idx = INT_MAX;
	cur = stack->top;
	while (cur)
	{
		if (cur->idx < min_idx)
		{
			min_idx = cur->idx;
			min = cur;
		}
		cur = cur->next;
		if (cur == stack->top)
			break ;
	}
	return (min);
}
