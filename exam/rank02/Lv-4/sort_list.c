/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:44:23 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/18 09:09:42 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*cur;
	int	tmp;

	cur = lst;
	while (cur->next != NULL)
	{
		if ((*cmp)(cur->data, cur->next->data) == 0)
		{
			tmp = cur->data;
			cur->data = cur->next->data;
			cur->next->data = tmp;
			cur = lst;
		}
		else
			cur = cur->next;
	}
	return (lst);
}
