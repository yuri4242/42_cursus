#include "ft_printf.h"

int	print_hex_lower(va_list ap, t_flags flags)
{
	unsigned int	n;
	int				len;

	n = va_arg(ap, unsigned int);
	if (flags.dot && flags.precision == 0 && n == 0)
		return (ptf_print_padding(flags.width, ' '));
	len = get_hex_len(n);
	return (print_hex_integer(n, flags, len, "0123456789abcdef"));
}
