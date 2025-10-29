/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:27:10 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/29 10:36:27 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	count_d(long n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char *ft_itoa(int nbr)
{
	size_t	degits;
	char	*ret;
	long	n;

	n = (long)nbr;
	if (n == 0)
		return (ret = "0");
	degits = count_d(n);
	ret = malloc(sizeof(char)* (degits + 1));
	if (ret == NULL)
		return (NULL);
	ret[degits] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		ret[degits] = (n % 10) + '0';
		n /= 10;
		degits--;
	}
	return (ret);
}

#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int nbr = -42;
	char *ret = ft_itoa(nbr);
	printf("ret: %s\n", ret);

	nbr = INT_MAX;
	ret = ft_itoa(nbr);
	printf("ret: %s\n", ret);

	nbr = INT_MIN;
	ret = ft_itoa(nbr);
	printf("ret: %s\n", ret);

	nbr = 0;
	ret = ft_itoa(nbr);
	printf("ret: %s\n", ret);
}

