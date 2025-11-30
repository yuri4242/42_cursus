/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:55:42 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/30 18:03:04 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->prev;
	stack->bottom = stack->bottom->prev;
}

void	rra(t_stack *stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	rra(stack_a, 0);
	rra(stack_b, 0);
	if (print)
		ft_printf("rrr\n");
}
