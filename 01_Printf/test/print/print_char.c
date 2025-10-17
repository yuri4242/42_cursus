#include "ft_printf.h"

int	print_char(va_list ap, t_flags flags)
{
	unsigned char	c;
	int				count;
	int				padding_len;

	c = (unsigned char)va_arg(ap, int);
	count = 0;
	padding_len = flags.width - 1;
	if (padding_len < 0)
		padding_len = 0;
	if (flags.minus == 0)
		count += ptf_print_padding(padding_len, ' ');
	count += ptf_putchar(c);
	if (flags.minus == 1)
		count += ptf_print_padding(padding_len, ' ');
	return (count);
}
