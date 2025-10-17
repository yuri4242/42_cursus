#include "ft_printf.h"

int	ptf_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ptf_putnbr_unsigned(n / 10);
	count += ptf_putchar((n % 10) + '0');
	return (count);
}
