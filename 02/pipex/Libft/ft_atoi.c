/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:57:43 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/19 12:57:47 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v'
		|| c == ' ');
}

static int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

static int	is_overflow(long long result, int digit, int sign)
{
	long long	int_max;
	long long	int_min;

	int_max = 2147483647;
	int_min = -2147483648;
	if (sign == 1)
	{
		if (result > int_max / 10
			|| (result == int_max / 10
				&& digit > int_max % 10))
			return (1);
	}
	else
	{
		if (result > -(long long)int_min / 10
			|| (result == -(long long)int_min / 10
				&& digit > -(long long)int_min % 10))
			return (-1);
	}
	return (0);
}

static int	parse_digits(const char *nptr, int sign)
{
	long long	result;
	int			overflow;
	int			i;

	result = 0;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		overflow = is_overflow(result, nptr[i] - '0', sign);
		if (overflow == 1)
			return (2147483647);
		if (overflow == -1)
			return (-2147483648);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				sign;

	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	return (parse_digits(nptr + i, sign));
}
