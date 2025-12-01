/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:18:18 by yikebata          #+#    #+#             */
/*   Updated: 2025/12/01 17:56:52 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_start(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		two_sort(stack_a);
	else if (stack_a->size == 3)
		three_sort(stack_a);
	else if (stack_a->size <= 5)
		four_five_sort(stack_a, stack_b);
	else
		large_sort(stack_a, stack_b);
}

static int	is_sorted(t_stack *stack)
{
	t_node	*cur;

	if (!stack || !stack->top || stack->size < 2)
		return (1);
	cur = stack->top;
	while (cur->next != stack->top)
	{
		if (cur->idx > cur->next->idx)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void	push_swap(char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (create_stacks(&stack_a, &stack_b) == EXIT_FAILURE)
		return ;
	if (args_to_lst(args, stack_a) == EXIT_FAILURE)
	{
		free_stacks(&stack_a, &stack_b);
		return ;
	}
	if (coordinate_compression(stack_a) == EXIT_FAILURE)
	{
		free_stacks(&stack_a, &stack_b);
		return ;
	}
	if (is_sorted(stack_a))
	{
		free_stacks(&stack_a, &stack_b);
		return ;
	}
	sort_start(stack_a, stack_b);
	free_stacks(&stack_a, &stack_b);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	push_swap(av);
	return (0);
}
