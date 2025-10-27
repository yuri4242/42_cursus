/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:17:51 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/24 13:40:08 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *s)
{
	size_t	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = gnl_strlen(s);
	while (i <= s_len)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = malloc(1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (s2 == NULL)
		return (free(s1), NULL);
	len_s1 = gnl_strlen(s1);
	len_s2 = gnl_strlen(s2);
	join = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (join == NULL)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (i < len_s1)
		join[i++] = s1[j++];
	j = 0;
	while (j < len_s2 + 1)
		join[i++] = s2[j++];
	return (free(s1), join);
}

int	free_all(char **leftover, char **buf)
{
	if (leftover != NULL)
	{
		free(*leftover);
		*leftover = NULL;
	}
	free(*buf);
	return (-1);
}


char	*update_leftover(char *leftover)
{
	char	*new;
	char	*head_ptr;
	size_t	len_new;

	if (leftover == NULL)
		return (NULL);
	head_ptr = gnl_strchr(leftover, '\n');
	if (head_ptr == NULL)
		return (free(leftover, NULL));
	len_new = gnl_strlen(head_ptr + 1);
	new = malloc(sizeof(char) * (len_new + 1));
	if (new == NULL)
		return (free(leftover), NULL);
	i = 0;
	while (i < len_new)
	{
		new[i] = (head_ptr + 1)[i];
		i++;
	}
	new[len_new] = '\0';
	free(leftover);
	return (new);
}
