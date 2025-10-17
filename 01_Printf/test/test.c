#include "ft_printf.h"
#include <stdio.h>

void	print_flags(const t_flags *flags)
{
	printf("\n--- [DEBUG] Flags Struct ---\n");
	printf("  flags->minus     : %d\n", flags->minus);
	printf("  flags->zero      : %d\n", flags->zero);
	printf("  flags->width     : %d\n", flags->width);
	printf("  flags->dot       : %d\n", flags->dot);
	printf("  flags->precision : %d\n", flags->precision);
	printf("----------------------------\n\n");
}

int	parse_flag_and_specifier(va_list ap, const char **fmt)
{
	t_flags	flags;

	init_flags(&flags);
	parse_flags(fmt, &flags);
	parse_width(fmt, ap, &flags);
	parse_precision(fmt, ap, &flags);
//	print_flags(&flags);
	return (parse_specifier(ap, **fmt, flags));
}

int	supporter_printf(const char *fmt, va_list ap)
{
	int	count;

	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			count += parse_flag_and_specifier(ap, &fmt);
		}
		else
			count += ptf_putchar(*fmt);
		fmt++;
	}
	return (count);
}

int ft_printf(const char *fmt, ...)
{
	int count;
	va_list ap;
	
	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	count = supporter_printf(fmt, ap);
	va_end(ap);
	return (count);
}
