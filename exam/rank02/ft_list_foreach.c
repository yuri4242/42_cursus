/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:57:26 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/29 10:03:56 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current;

	current = begin_list;
	while (current != NULL)
	{
		if (current->data != NULL) //ここのNULLガードはなくても良さそう
			(*f)(current->data);
		current = current->next;
	}
}
