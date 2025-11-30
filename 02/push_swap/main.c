/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:18:18 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/30 18:26:41 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = stack->top;
	while (i < stack->size)
	{
		ft_printf("%d\n", cur->val);
		cur = cur->next;
		i++;
	}
}

void	push_swap(char **args)
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
//	print_stack(stack_a);
	if (stack_a->size == 2)
		two_sort(stack_a);
	free_stacks(&stack_a, &stack_b);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	push_swap(av);
	return (0);
}
