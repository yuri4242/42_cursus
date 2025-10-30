/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:42:45 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/30 16:01:52 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	first_word;

	i = 0;
	first_word = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
			i++;
		i--;
		while (i >= 0)
		{
			while (i >= 0 && (av[1][i] == ' ' || av[1][i] == '\t'))
				i--;
			j = i;
			while (j >= 0 && (av[1][j] != ' ' || av[1][j] != '\t'))
				j--;
			if (first_word)
				write(1, " ", 1);
			write(1, &av[1][j + 1], i - j);
			first_word = 1;
			i = j;
		}
	}
	write(1, "\n", 1);
	return (0);
}
