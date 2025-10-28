/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:17:52 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/28 10:42:11 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

static int	is_deli(char c)
{
	return (c == ' '
			|| c == '\t'
			|| c == '\n');
}

static size_t	count_word(char *str)
{
	size_t	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str != '\0')
	{
		if (!(is_deli(*str)) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_deli(*str))
			in_word = 0;
		str++;
	}
	return (count);
}

static char	**free_all(char **ret)
{
	int	i;
	
	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

static size_t	ft_strlen(char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static char *ft_substr(char *str, unsigned int start, unsigned int len)
{
	char *ret;
	size_t len_cpy;
	size_t len_str;

	if (str == NULL)
		return (NULL);
	len_str = ft_strlen(str);
	len_cpy = 0;
	if (len_str <= start)
		return (malloc(0));
	if (len_str - start > len)
		len_cpy = len;
	else
		len_cpy = len_str - start;
	ret = malloc(sizeof(char *) * (len_cpy + 1));
	int i = 0;
	while (i < len_cpy)
	{
		ret[i] = str[start + i];
		i++;
	}
	ret[len_cpy] = '\0';
	return (ret);
}

static char	**do_split(char **ret, char const *str, size_t word_n)
{
	size_t	i;
	size_t	word_start;
	size_t	word_len;

	i = 0;
	word_start = 0;
	while (i < word_n)
	{
		while (is_deli(str[word_start]))
			word_start++;
		word_len = 0;
		while (!(is_deli(str[word_start + word_len])))
			word_len++;
		ret[i] = ft_substr((char *)str, word_start, word_len);
		if (ret[i] == NULL)
			return (free_all(ret));
		word_start += word_len;
		i++;
	}
	ret[word_n] = NULL;
	return (ret);
}

char	**ft_split(char *str)
{
	char **splits;
	size_t	word_n;

	if (str == NULL)
		return (NULL);
	word_n = count_word(str);
	printf("word_n: %zu\n", word_n);
	splits = malloc(sizeof(char *) * (word_n + 1));
	if (splits == NULL)
		return (NULL);
	return (do_split(splits, str, word_n));
}


void	print_split(char **ret)
{
	int	i = 0;

	while (ret[i])
	{
		printf("%s\n", ret[i]);
		i++;
	}
}

int	main(void)
{
	char *str = "Hello world 42 tokyo! !";
	char **ret;

	ret = ft_split(str);
	if (ret == NULL)
		printf("ret is NULL.\n");
	print_split(ret);
	return (0);
}
