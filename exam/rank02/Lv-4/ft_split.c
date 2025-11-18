/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:17:52 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/18 10:16:20 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	return (count);
}

void	copy_word(char *tab, char *str, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
		tab[i++] = str[start++];
	tab[i] = '\0';
}

int	find_next_word(char *str, int *start, int *end)
{
	int	i;

	i = *end;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	*start = i;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	*end = i;
	return (*start < *end);
}

int	fill_words(char **tab, char *str)
{
	int	i;
	int	word;
	int	start;
	int	end;

	i = 0;
	word = 0;
	start = 0;
	end = 0;
	while (find_next_word(str, &start, &end))
	{
		tab[word] = malloc(sizeof(char) * (end -start + 1));
		if (tab[word] == NULL)
		{
			i = 0;
			while (i < word)
				free(tab[i++]);
			free(tab);
			return (0);
		}
		copy_word(tab[word], str, start, end);
		word++;
	}
	tab[word] = NULL;
	return (1);
}

char	**ft_split(char *str)
{
	char **out;
	int	size;

	size = count_words(str);
	out = malloc(sizeof(char *) * (size + 1));
	if (out == NULL)
		return (NULL);
	if (!fill_words(out, str))
	{
		free(out);
		return (NULL);
	}
	return (out);
}

void	print_split(char **ret)
{
	int	i = 0;

	while (ret[i])
	{
		printf("%s\n", ret[i]);
		free(ret[i]);
		i++;
	}
	free(ret);
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
