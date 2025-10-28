/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:03:41 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/28 09:16:41 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int i;
	int	num;

	if (ac != 2)
		return (1);
	i = 2;
	num = atoi(av[1]);
	if (num == 1)
		printf("1");
	while (i <= num)
	{
		if (num % i == 0)
		{
			printf("%d", i);
			if (i != num)
				printf("*");
			num /= i;
		}
		else
			i++;
	}
	printf("\n");
	return (0);
}
