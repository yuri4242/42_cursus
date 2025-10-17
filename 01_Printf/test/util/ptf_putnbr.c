#include "ft_printf.h"

int	ptf_putnbr(int n)
{
	long	ln;
	int		count;

	ln = n;
	count = 0;
	if (ln == 0)
		return (ptf_putchar('0'));
	if (ln < 0)
	{
		count += ptf_putchar('-');
		ln = -ln;
	}
	if (ln > 9)
		count += ptf_putnbr(ln / 10);
	count += ptf_putchar((ln % 10) + '0');
	return (count);
}
