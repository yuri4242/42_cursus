/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:27:10 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/18 10:42:59 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	count_digit(long num)
{
	size_t	count;

	count = 0;
	if (num <= 0)
	{
		num *= -1;
		count++;
	}
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

char *ft_itoa(int num)
{
	char *res;
	size_t	size;
	long	ln;

	ln = (long)num;	
	size = count_digit(ln);
	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	size--;
	if (ln == 0)
		res[0] = '0';
	if (ln < 0)
	{
		res[0] = '-';
		ln *= -1;
	}
	while (ln > 9)
	{
		res[size] = ln % 10 + '0';
		ln /= 10;
		size--;
	}
	res[size] = ln + '0';
	return (res);
}

#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	(void)ac;
	printf("%s\n", ft_itoa(atoi(av[1])));
	return (0);
}
