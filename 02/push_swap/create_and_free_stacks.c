/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_free_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:29:54 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/29 18:32:04 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = ft_calloc(1, sizeof(t_stack));
	if (!*stack_a)
		return (EXIT_FAILURE);
	*stack_b = ft_calloc(1, sizeof(t_stack));
	if (!*stack_b)
	{
		free(*stack_a);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	free_stack_content(t_stack *stack)
{
	t_node	*cur;
	t_node	*tmp;
	int		i;

	if (!stack || !stack->top)
		return ;
	i = 0;
	cur = stack->top;
	while (i < stack->size)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
		i++;
	}
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a)
	{
		free_stack_content(*stack_a);
		free(*stack_a);
		*stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		free_stack_content(*stack_b);
		free(*stack_b);
		*stack_b = NULL;
	}
}
