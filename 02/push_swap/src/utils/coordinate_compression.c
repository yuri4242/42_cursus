/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:31:02 by yikebata          #+#    #+#             */
/*   Updated: 2025/12/01 09:32:17 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	cpy_stack_val_to_arr(t_stack *stack, int *tab)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = stack->top;
	while (i < stack->size)
	{
		tab[i] = cur->val;
		cur = cur->next;
		i++;
	}
}

static void	set_index(t_stack *stack, int *tab)
{
	int		i;
	int		j;
	t_node	*cur;

	i = 0;
	cur = stack->top;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (tab[j] == cur->val)
			{
				cur->idx = j;
				break ;
			}
			j++;
		}
		cur = cur->next;
		i++;
	}
}

int	coordinate_compression(t_stack *stack)
{
	int	*tab;

	tab = malloc(sizeof(int) * stack->size);
	if (!tab)
		return (EXIT_FAILURE);
	cpy_stack_val_to_arr(stack, tab);
	sort_int_tab(tab, stack->size);
	set_index(stack, tab);
	free(tab);
	return (EXIT_SUCCESS);
}
