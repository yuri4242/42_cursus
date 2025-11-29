/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:14:27 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/29 18:58:09 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *arg)
{
	int		i;
	char	c;

	i = 0;
	while (arg[i])
	{
		c = arg[i];
		if (!ft_isdigit(c))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_overflow(long num)
{
	if (num > (long)INT_MAX || num < (long)INT_MIN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_dup(int num, t_stack *stack)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = stack->top;
	while (i < stack->size)
	{
		if (num == cur->val)
			return (EXIT_FAILURE);
		cur = cur->next;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	add_to_stack(int num, t_stack *stack)
{
	ps_lstadd_back(&stack->top, ps_lstnew(num));
	stack->size++;
}
