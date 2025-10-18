/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata  <yikebata@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:59:35 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/15 23:07:17 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		del(current->content);
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*lst = NULL;
}
