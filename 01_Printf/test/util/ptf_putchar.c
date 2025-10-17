#include "ft_printf.h"

int	ptf_putchar(char c)
{
	return (write(1, &c, 1));
}
