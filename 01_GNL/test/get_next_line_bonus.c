/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:17:22 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/24 13:39:43 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char const *leftover)
{
	char	*line;
	size_t	len;
	size_t	i;

	if (leftover == NULL || *leftover == '\0')
		return (NULL);
	len = 0;
	while (leftover[len] && leftover[len] != '\n')
		len++;
	if (leftover[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static int	read_one_line(int fd, char **leftover)
{
	char	*buf;
	ssize_t	read_bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (free_all(leftover, &buf));
	while (gnl_strchr(*leftover, '\n') == NULL)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_all(leftover, &buf));
		if (read_bytes == 0)
		{
			free(buf);
			return (0);
		}
		buf[read_bytes] = '\0';
		*leftover = gnl_strjoin(*leftover, buf);
		if (*leftover == NULL)
			return (free_all(leftover, &buf));
	}
	free(buf);
	return (1);
}

static t_fds	*create_node(t_fds **head, int fd)
{
	t_fds	*current;

	if (head == NULL)
		return (NULL);
	current = *head;
	while (current != NULL)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = malloc(sizeof(t_fds));
	if (current == NULL)
		return (NULL);
	current->fd = fd;
	current->leftover = NULL;
	current->next = NULL;
	*head = current;
	return (current);
}

static void	remove_node(t_fds **head, int fd)
{
	t_fds	*current;
	t_fds	*prev;

	if (head == NULL || *head == NULL)
		return ;
	current = *head;
	prev = NULL;
	while (current != NULL)
	{
		if (current->fd == fd)
		{
			if (prev == NULL)
				*head = current->next;
			else
				prev->next = current->next;
			free(current->leftover);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

char	*get_next_line(int fd)
{
	static t_fds	*head = NULL;
	t_fds			*current;
	char			*line;
	char			*new_lo;
	int				status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = create_node(&head, fd);
	if (current == NULL)
		return (NULL);
	status = read_one_line(fd, &current->leftover);
	if (status <= 0 && (current->leftover == NULL
			|| *(current->lefover) == '\0'))
	{
		remove_node(&head, fd);
		return (NULL);
	}
	line = extract_line(current->leftover);
	if (line == NULL)
		return (remove_node(&head, fd), NULL);
	new_lo = update_leftover(current->leftover);
	current->leftover = new_lo;
	return (line);
}
