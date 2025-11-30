/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:09:36 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/30 18:21:07 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_stack *stack_a)
{
	int	top_val;
	int	bottom_val;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	if (stack_a->size != 2)
		return ;
	top_val = stack_a->top->val;
	bottom_val = stack_a->top->next->val;
	if (top_val > bottom_val)
		sa(stack_a, 1);
}
