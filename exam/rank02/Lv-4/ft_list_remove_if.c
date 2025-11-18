/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:25:16 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/18 12:09:08 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	**cur;
	t_list	*tmp;

	if (begin_list == NULL)
		return ;
	cur = begin_list;
	while (*cur)
	{
		if ((*cmp)(data_ref, (*cur)->data) == 0)
		{
			tmp = *cur;
			*cur = tmp->next;
			free(tmp);
		}
		else
			cur = &((*cur)->next);
	}
}
