#include "ft_printf.h"

int	ptf_putnbr_hex_upper(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ptf_putnbr_hex_upper(n / 16);
	count += ptf_putchar(hex[n % 16]);
	return (count);
}
