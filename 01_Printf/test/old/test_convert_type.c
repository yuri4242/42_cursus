#include "ft_printf.h"

int parse_convert_type(va_list ap, char specifier)
{
	(void)ap;

	if (specifier == 'c')
		return (print_char(ap));
	else if (specifier == 's')
		return (print_str(ap)); 
	else if (specifier == 'p')
		return (print_pointer(ap)); 
	else if (specifier == 'd' || specifier == 'i')
		return (print_signed_nbr(ap)); 
	else if (specifier == 'u')
		return (print_unsigned_nbr(ap)); 
	else if (specifier == 'x')
		return (print_hex_lower(ap)); 
	else if (specifier == 'X')
		return (print_hex_upper(ap)); 
	else if (specifier == '%')
		return (ptf_putchar('%'));
	return (0);
}

int ft_printf(const char *fmt, ...)
{
	int count;
	va_list ap;
	
	if (fmt == NULL)
		return (-1);
	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			count += parse_convert_type(ap, *fmt);//parseの先でtypeごとの出力。
		}
		else
			count += ptf_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (count);
}

#include <limits.h>   // UINT_MAX のため

int	main(void)
{
	int		num = 42;
	char	*str = "Hello";

	ft_printf("--- テスト開始 ---\n");
	ft_printf("ただの文字列です。\n");
	ft_printf("パーセント記号: %%\n");
	ft_printf("変換子c: %c\n", 'A');
	ft_printf("変換子s: %s\n", "Hello");
	ft_printf("変換子d: %d\n", 123);
	ft_printf("ft_printf (u): %u, %u, %u, %u\n", 123, 0, -1, UINT_MAX);
	ft_printf("ft_printf (x): %x, %x, %x, %x\n", 255, 0, -1, INT_MAX);
	ft_printf("ft_printf (X): %X, %X, %X, %X\n", 255, 0, -1, INT_MAX);
	ft_printf("ft_printf (int*): %p\n", &num);
	ft_printf("ft_printf (char*): %p\n", str);
	ft_printf("ft_printf (NULL): %p\n", NULL);
	ft_printf("未対応の変換子: %z\n");
	ft_printf("--- テスト終了 ---\n");
	return (0);
}
