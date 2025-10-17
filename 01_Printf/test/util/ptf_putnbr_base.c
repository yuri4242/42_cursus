#include "ft_printf.h"

int	ptf_putnbr_base(unsigned long n, const char *base)
{
	int				count;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (n >= base_len)
		count += ptf_putnbr_base(n / base_len, base);
	count += ptf_putchar(base[n % base_len]);
	return (count);
}
