/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:42:45 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/18 12:41:36 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	end;
	int	start;
	int	first;

	if (ac == 2)
	{
		end = 0;
		first = 1;
		while (av[1][end] != '\0')
			end++;
		end--;
		while (end >= 0)
		{
			while (end >= 0 && (av[1][end] == ' ' || av[1][end] == '\t'))
				end--;
			start = end;
			while (start >= 0 && av[1][start] != ' ' && av[1][start] != '\t')
				start--;
			if (!first)
				write(1, " ", 1);
			write(1, &av[1][start + 1], end - start);
			first = 0;
			end = start;
		}
	}
	write(1, "\n", 1);
	return (0);
}
