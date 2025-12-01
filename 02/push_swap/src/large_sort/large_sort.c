/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:06:45 by yikebata          #+#    #+#             */
/*   Updated: 2025/12/01 16:29:32 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_to_top(t_stack *stack)
{
	t_node	*min;

	update_index(stack);
	min = find_min(stack);
	while (stack->top != min)
	{
		if (min->above_median_flag)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}

static void	chunk_move_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	range;

	i = 0;
	if (stack_a->size <= 100)
		range = SMALL_CHUNK_SIZE;
	else
		range = LARGE_CHUNK_SIZE;
	while (stack_a->size > 3)
	{
		if (stack_a->top->idx <= i)
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			i++;
		}
		else if (stack_a->top->idx <= i + range)
		{
			pb(stack_a, stack_b, 1);
			i++;
		}
		else
			ra(stack_a, 1);
	}
}

static void	update_node_info(t_stack *stack_a, t_stack *stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	set_target(stack_a, stack_b);
	cal_move_cost(stack_a, stack_b);
	get_cheapest(stack_b);
}

static void	move_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(stack_b);
	if (cheapest->above_median_flag && cheapest->target->above_median_flag)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!cheapest->above_median_flag
		&& !cheapest->target->above_median_flag)
		reverse_rotate_both(stack_a, stack_b, cheapest);
	additional_rotate(stack_a, cheapest->target, 'a');
	additional_rotate(stack_b, cheapest, 'b');
	pa(stack_a, stack_b, 1);
}

void	large_sort(t_stack *stack_a, t_stack *stack_b)
{
	chunk_move_to_b(stack_a, stack_b);
	three_sort(stack_a);
	while (stack_b->size > 0)
	{
		update_node_info(stack_a, stack_b);
		move_to_a(stack_a, stack_b);
	}
	min_to_top(stack_a);
}
