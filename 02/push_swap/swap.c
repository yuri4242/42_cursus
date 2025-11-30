/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:45:20 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/30 17:51:46 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	if (stack->size == 2)
	{
		stack->bottom = stack->top;
		stack->top = stack->top->next;
		return ;
	}
	first = stack->top;
	second = first->next;
	first->next = second->next;
	first->next->prev = first;
	second->prev = first->prev;
	second->prev->next = second;
	first->prev = second;
	second->next = first;
	stack->top = second;
}

void	sa(t_stack *stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack *stack_b, int print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		ft_printf("ss\n");
}
