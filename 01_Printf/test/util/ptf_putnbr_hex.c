#include "ft_printf.h"

int	ptf_putnbr_hex(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ptf_putnbr_hex(n / 16);
	count += ptf_putchar(hex[n % 16]);
	return (count);
}
