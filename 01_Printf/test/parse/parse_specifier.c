#include "ft_printf.h"

int	parse_specifier(va_list ap, char specifier, t_flags flags)
{
	if (specifier == 'c')
		return (print_char(ap, flags));
	else if (specifier == 's')
		return (print_str(ap, flags));
	else if (specifier == 'p')
		return (print_pointer(ap, flags));
	else if (specifier == 'd' || specifier == 'i')
		return (print_signed_nbr(ap, flags));
	else if (specifier == 'u')
		return (print_unsigned_nbr(ap, flags));
	else if (specifier == 'x')
		return (print_hex_lower(ap, flags));
	else if (specifier == 'X')
		return (print_hex_upper(ap, flags));
	else if (specifier == '%')
		return (ptf_putchar('%'));
	return (0);
}
