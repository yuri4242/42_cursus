#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void transform_char(unsigned int index, char *character)
{
	if (index % 2 == 0)
		*character = ft_toupper(*character);
	else
		*character = ft_tolower(*character);
}

int main(void)
{
	// テストケース1：基本的な英字の文字列
	char str1[] = "HeLlO wOrLd!";
	printf("Original  [1]: \"%s\"\n", str1);
	ft_striteri(str1, &transform_char);
	printf("Modified  [1]: \"%s\"\n\n", str1);

	// テストケース2：すべて小文字の文字列
	char str2[] = "abcdefghijklmnopqrstuvwxyz";
	printf("Original  [2]: \"%s\"\n", str2);
	ft_striteri(str2, &transform_char);
	printf("Modified  [2]: \"%s\"\n\n", str2);

	// テストケース3：空の文字列
	char str3[] = "";
	printf("Original  [3]: \"%s\"\n", str3);
	ft_striteri(str3, &transform_char);
	printf("Modified  [3]: \"%s\"\n\n", str3);

	// テストケース4：NULLポインタ
	printf("Testing with NULL pointer...\n");
	ft_striteri(NULL, &transform_char);
	printf("Test with NULL pointer finished safely.\n\n");

	// テストケース5：NULLポインタ
	char str5[] = "abcdefghijklmnopqrstuvwxyz";
	printf("Testing with NULL pointer...\n");
	ft_striteri(str5, NULL);
	printf("Test with NULL pointer finished safely.\n");

	return (0);
}
