/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:49:29 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/30 18:02:35 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	join_to_dest(t_stack *stack_d, t_node *node_to_move)
{
	if (stack_d->size == 0)
	{
		stack_d->top = node_to_move;
		stack_d->bottom = node_to_move;
		node_to_move->next = node_to_move;
		node_to_move->prev = node_to_move;
	}
	else
	{
		node_to_move->next = stack_d->top;
		node_to_move->prev = stack_d->bottom;
		stack_d->top->prev = node_to_move;
		stack_d->bottom->next = node_to_move;
		stack_d->top = node_to_move;
	}
	stack_d->size++;
}

static void	move_from_src(t_stack *stack_s, t_node *node_to_move)
{
	if (stack_s->size == 1)
	{
		stack_s->top = NULL;
		stack_s->bottom = NULL;
	}
	else
	{
		stack_s->top = node_to_move->next;
		stack_s->top->prev = stack_s->bottom;
		stack_s->bottom->next = stack_s->top;
	}
	stack_s->size--;
}

static void	push(t_stack *stack_s, t_stack *stack_d)
{
	t_node	*node_to_move;

	if (!stack_s || !stack_s->top)
		return ;
	node_to_move = stack_s->top;
	move_from_src(stack_s, node_to_move);
	join_to_dest(stack_d, node_to_move);
}

void	pa(t_stack *stack_a, t_stack *stack_b, int print)
{
	push(stack_b, stack_a);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	push(stack_a, stack_b);
	if (print)
		ft_printf("pb\n");
}
