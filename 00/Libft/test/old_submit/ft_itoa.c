#include "libft.h"

size_t	count_digits(int n)
{
	long long	l_n;
	size_t		count;

	l_n = (long long)n;
	count = 0;
	if (l_n <= 0)
	{
		l_n *= -1;
		count++;
	}
	while (l_n > 0)
	{
		l_n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*itoa;
	size_t		len;
	long long	num;

	num = (long long)n;
	len = count_digits(n);
	itoa = malloc(sizeof(char) * (len + 1));
	if (itoa == NULL)
		return (NULL);
	itoa[len] = '\0';
	if (num == 0)
		itoa[0] = '0';
	if (num < 0)
	{
		itoa[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		len--;
		itoa[len] = (num % 10) + '0';
		num /= 10;
	}
	return (itoa);
}
