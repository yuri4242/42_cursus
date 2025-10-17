#include "ft_printf.h"

int	print_hex_integer(unsigned int n, t_flags flags, int len, char *base)
{
	int		count;
	int		zero_len;
	int		padding_len;
	char	pad_char;

	count = 0;
	zero_len = 0;
	if (flags.precision > len)
		zero_len = flags.precision - len;
	padding_len = 0;
	if (flags.width > len + zero_len)
		padding_len = flags.width - (len + zero_len);
	pad_char = ' ';
	if (flags.zero && !flags.minus && !flags.dot)
		pad_char = '0';
	if (!flags.minus)
		count += ptf_print_padding(padding_len, pad_char);
	count += ptf_print_padding(zero_len, '0');
	count += ptf_putnbr_base(n, base);
	if (flags.minus)
		count += ptf_print_padding(padding_len, ' ');
	return (count);
}
