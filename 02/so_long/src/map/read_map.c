/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:15:37 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/28 11:33:01 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**lst_to_arr(t_list *head)
{
	int		size;
	int		i;
	char	**map;
	t_list	*tmp;
	t_list	*next_node;

	size = ft_lstsize(head);
	map = malloc(sizeof(t_list) * (size + 1));
	if (map == NULL)
	{
		ft_lstclear(&head, free);
		return (NULL);
	}
	i = 0;
	tmp = head;
	while (tmp != NULL)
	{
		map[i] = tmp->content;
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**read_map(char *filepath)
{
	int		fd;
	char	*raw_line;
	char	*trimmed_line;
	t_list	*head;

	head = NULL;
	fd = open(filepath, O_RDONLY);
	while (1)
	{
		raw_line = ft_gnl(fd);
		if (raw_line == NULL)
			break ;
		trimmed_line = ft_strtrim(raw_line, "\n");
		free(raw_line);
		if (trimmed_line == NULL)
		{
			ft_lstclear(&head, free);
			close(fd);
			return (NULL);
		}
		ft_lstadd_back(&head, ft_lstnew(trimmed_line));
	}
	close(fd);
	return (lst_to_arr(head));
}
