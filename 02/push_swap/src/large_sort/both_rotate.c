/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:33:30 by yikebata          #+#    #+#             */
/*   Updated: 2025/12/01 17:04:21 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack *a, t_stack *b, t_node *cheapest)
{
	while (b->top != cheapest && a->top != cheapest->target)
		rr(a, b, 1);
}

void	reverse_rotate_both(t_stack *a, t_stack *b, t_node *cheapest)
{
	while (b->top != cheapest && a->top != cheapest->target)
		rrr(a, b, 1);
}
