/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:14:27 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/30 18:24:04 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *arg)
{
	int		i;
	char	c;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (EXIT_FAILURE);
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
	t_node	*new;

	new = ps_lstnew(num);
	if (!new)
		return ;
	ps_lstadd_back(&stack->top, new);
	stack->bottom = new;
	stack->size++;
}
