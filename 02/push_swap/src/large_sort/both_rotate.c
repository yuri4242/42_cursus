/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:33:30 by yikebata          #+#    #+#             */
/*   Updated: 2025/12/01 16:35:29 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack *stack_a, t_stack *stack_b, t_node *cheapest)
{
	while (stack_b->top != cheapest && stack_a->top != cheapest->target)
		rr(stack_a, stack_b, 1);
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b\
, t_node *cheapest)
{
	while (stack_b->top != cheapest && stack_a->top != cheapest->target)
		rrr(stack_a, stack_b, 1);
}
