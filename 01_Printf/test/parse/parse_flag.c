#include "ft_printf.h"

void	parse_flags(const char **fmt, t_flags *flags)
{
	while (is_flag(**fmt))
	{
		if (**fmt == '-')
			flags->minus = 1;
		else if (**fmt == '0')
			flags->zero = 1;
		(*fmt)++;
	}
}
