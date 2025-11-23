/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:35:03 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/23 15:15:21 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	count_args(const char *s)
{
	int	count;
	int	state;

	count = 0;
	state = NORMAL;
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (*s)
			count++;
		while (*s && (state != NORMAL || !ft_isspace(*s)))
		{
			if (*s == '\'' || *s == '"')
				state_parser(*s, &state);
			else if (*s == '\\' && *(s + 1) && state != S_QUOTE)
				s++;
			else if (state == NORMAL && ft_isspace(*s))
				break ;
			s++;
		}
	}
	return (count);
}

static char	*copy_and_strip(const char *src, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;
	int		state;

	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	state = NORMAL;
	while (src[i] && j < len)
	{
		if (src[i] == '\'' || src[i] == '"')
			state_parser(src[i], &state);
		else if (src[i] == '\\' && src[i + 1] && state != S_QUOTE)
			dest[j++] = src[++i];
		else
			dest[j++] = src[i];
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

static size_t	get_token_len(const char *s)
{
	size_t	i;
	int		state;

	i = 0;
	state = NORMAL;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			state_parser(s[i], &state);
		else if (s[i] == '\\' && s[i + 1] && state != S_QUOTE)
			i++;
		else if (state == NORMAL && ft_isspace(s[i]))
			break ;
		i++;
	}
	return (i);
}

static int	do_split(const char *cmd, size_t *src_i, char ***res, int *arr_i)
{
	size_t	src_len;

	while (cmd[*src_i] && ft_isspace(cmd[*src_i]))
		(*src_i)++;
	src_len = get_token_len(cmd + *src_i);
	if (src_len == 0)
		return (0);
	(*res)[*arr_i] = copy_and_strip(cmd + *src_i, src_len);
	if (!(*res)[*arr_i])
		return (-1);
	*src_i += src_len;
	(*arr_i)++;
	return (1);
}

char	**split_cmds(const char *cmd_str)
{
	char	**res;
	int		arr_idx;
	size_t	src_idx;
	int		status;

	res = (char **)malloc(sizeof(char *) * (count_args(cmd_str) + 1));
	if (!res)
		return (NULL);
	arr_idx = 0;
	src_idx = 0;
	while (cmd_str[src_idx])
	{
		status = do_split(cmd_str, &src_idx, &res, &arr_idx);
		if (status == -1)
		{
			free_all(res);
			return (NULL);
		}
		if (status == 0)
			break ;
	}
	res[arr_idx] = NULL;
	return (res);
}
