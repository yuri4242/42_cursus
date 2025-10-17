#include "ft_printf.h"

int	is_flag(int c)
{
	return (c == '-'
		|| c == '0');
}
