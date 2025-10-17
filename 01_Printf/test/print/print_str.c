#include "ft_printf.h"

int	print_str(va_list ap, t_flags flags)
{
	char	*str;
	int		count;
	int		full_len;
	int		print_len;
	int		padding_len;

	str = (char *)va_arg(ap, char *);
	if (str == NULL)
		str = "(nil)";
	full_len = ft_strlen(str);
	count = 0;
	print_len = full_len;
	if (flags.dot == 1 && flags.precision < full_len)
		print_len = flags.precision;
	padding_len = flags.width - print_len;
	if (padding_len < 0)
		padding_len = 0;
	if (flags.minus == 0)
		count += ptf_print_padding(padding_len, ' ');
	count += write(1, str, print_len);
	if (flags.minus == 1)
		count += ptf_print_padding(padding_len, ' ');
	return (count);
}
