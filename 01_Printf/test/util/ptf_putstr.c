#include "ft_printf.h"

int	ptf_putstr(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}
