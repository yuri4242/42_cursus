#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int ptf_putchar(char c)
{
	return (write(1, &c, 1));
}

int ptf_putstr(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}

int parse_convert_type(va_list ap, char specifier)
{
	(void)ap;

	if (specifier == 'c')
		return (ptf_putstr("[c: charを出力]"));
	else if (specifier == 's')
		return (ptf_putstr("[s: 文字列を出力]")); 
	else if (specifier == 'p')
		return (ptf_putstr("[p: ポインタを出力]")); 
	else if (specifier == 'd' || specifier == 'i')
		return (ptf_putstr("[d/i: 10進数を出力]")); 
	else if (specifier == 'u')
		return (ptf_putstr("[u: 符号なし10進数を出力]")); 
	else if (specifier == 'x' || specifier == 'X')
		return (ptf_putstr("[x/X: 16進数を出力]")); 
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

int main(void)
{
    ft_printf("--- テスト開始 ---\n");
    ft_printf("ただの文字列です。\n");
    ft_printf("パーセント記号: %%\n");
    ft_printf("変換子c: %c\n", 'A');
    ft_printf("変換子s: %s\n", "Hello");
    ft_printf("変換子d: %d\n", 123);
    ft_printf("未対応の変換子: %z\n");
    ft_printf("--- テスト終了 ---\n");
    return (0);
}
