#include "ft_printf.h"

int	ptf_print_padding(int len, char c)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		count += ptf_putchar(c);
		len--;
	}
	return (count);
}
