/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:13:42 by yikebata          #+#    #+#             */
/*   Updated: 2025/12/01 16:18:12 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(t_stack *stack)
{
	t_node	*cur;
	int		i;
	int		median;

	if (!stack || !stack->top)
		return ;
	i = 0;
	median = stack->size / 2;
	cur = stack->top;
	while (i < stack->size)
	{
		cur->cur_pos = i;
		if (i <= median)
			cur->above_median_flag = true;
		else
			cur->above_median_flag = false;
		cur = cur->next;
		i++;
	}
}

static t_node	*find_target(t_stack *stack_a, int b_idx)
{
	t_node	*cur_a;
	t_node	*target;
	int		target_idx;

	target = NULL;
	target_idx = INT_MAX;
	cur_a = stack_a->top;
	while (cur_a)
	{
		if (cur_a->idx > b_idx && cur_a->idx < target_idx)
		{
			target_idx = cur_a->idx;
			target = cur_a;
		}
		cur_a = cur_a->next;
		if (cur_a == stack_a->top)
			break ;
	}
	return (target);
}

void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cur_b;
	t_node	*target;

	cur_b = stack_b->top;
	while (cur_b)
	{
		target = find_target(stack_a, cur_b->idx);
		if (!target)
			cur_b->target = find_min(stack_a);
		else
			cur_b->target = target;
		cur_b = cur_b->next;
		if (cur_b == stack_b->top)
			break ;
	}
}

static void	cal_optimal_cost(t_node *b, int cost_a, int cost_b)
{
	if (b->above_median_flag && b->target->above_median_flag)
	{
		if (cost_a > cost_b)
			b->optimal_cost = cost_a;
		else
			b->optimal_cost = cost_b;
	}
	else if (!b->above_median_flag && !b->target->above_median_flag)
	{
		if (cost_a > cost_b)
			b->optimal_cost = cost_a;
		else
			b->optimal_cost = cost_b;
	}
	else
		b->optimal_cost = cost_a + cost_b;
}

void	cal_move_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*b;
	int		cost_a;
	int		cost_b;

	b = stack_b->top;
	while (b)
	{
		if (b->above_median_flag)
			cost_b = b->cur_pos;
		else
			cost_b = stack_b->size - b->cur_pos;
		if (b->target->above_median_flag)
			cost_a = b->target->cur_pos;
		else
			cost_a = stack_a->size - b->target->cur_pos;
		cal_optimal_cost(b, cost_a, cost_b);
		b = b->next;
		if (b == stack_b->top)
			break ;
	}
}
