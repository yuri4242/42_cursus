#include "ft_printf.h"

int	is_flag_specifier(int c)
{
	return (is_flag(c) || is_specifier(c));
}
