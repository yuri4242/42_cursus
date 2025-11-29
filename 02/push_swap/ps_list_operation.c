/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:08:26 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/29 18:52:33 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ps_lstlast(t_node *lst)
{
	t_node	*cur;

	if (lst == NULL)
		return (NULL);
	cur = lst;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

void	ps_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*back;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	back = ps_lstlast(*lst);
	back->next = new;
}

t_node	*ps_lstnew(int val)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->val = val;
	return (new);
}
