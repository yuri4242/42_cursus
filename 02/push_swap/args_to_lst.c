/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:19:10 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/30 18:43:05 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_num_to_stack(char ***splitted_args, t_stack *stack_a)
{
	int		j;
	long	num;
	char	**args;

	args = *splitted_args;
	j = 0;
	while (args[j])
	{
		if (check_int(args[j]) == EXIT_FAILURE)
			return (err_print(splitted_args));
		num = ft_atol(args[j]);
		if (check_overflow(num) == EXIT_FAILURE)
			return (err_print(splitted_args));
		if (check_dup(num, stack_a) == EXIT_FAILURE)
			return (err_print(splitted_args));
		add_to_stack((int)num, stack_a);
		j++;
	}
	return (EXIT_SUCCESS);
}

int	args_to_lst(char **args, t_stack *stack_a)
{
	int		i;
	char	**splitted_args;

	i = 1;
	while (args[i])
	{
		splitted_args = ps_split(args[i]);
		if (!splitted_args)
			return (EXIT_FAILURE);
		if (set_num_to_stack(&splitted_args, stack_a))
			return (EXIT_FAILURE);
		free_arr(&splitted_args);
		i++;
	}
	if (stack_a->size > 0)
	{
		stack_a->bottom->next = stack_a->top;
		stack_a->top->prev = stack_a->bottom;
	}
	return (EXIT_SUCCESS);
}
