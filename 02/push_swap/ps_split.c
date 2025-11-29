/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:03:29 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/29 18:53:13 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (!ft_isspace(*s) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (ft_isspace(*s))
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**free_all(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
	return (NULL);
}

static char	**do_split(char **splits, char const *s, size_t word_count)
{
	size_t	i;
	size_t	word_start;
	size_t	word_len;

	i = 0;
	word_start = 0;
	while (i < word_count)
	{
		while (ft_isspace(s[word_start]))
			word_start++;
		word_len = 0;
		while (s[word_start + word_len]
			&& !ft_isspace(s[word_start + word_len]))
			word_len++;
		splits[i] = ft_substr(s, word_start, word_len);
		if (splits[i] == NULL)
			return (free_all(splits));
		word_start = word_start + word_len;
		i++;
	}
	splits[word_count] = NULL;
	return (splits);
}

char	**ps_split(char const *s)
{
	char	**splits;
	size_t	word_count;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s);
	splits = malloc(sizeof(char *) * (word_count + 1));
	if (splits == NULL)
		return (NULL);
	return (do_split(splits, s, word_count));
}
