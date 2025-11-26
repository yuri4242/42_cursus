#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h> 

// メモリがゼロで埋められているか検証する関数
int	verify_zero(const char *mem, size_t n)
{
	size_t i = 0;
	while (i < n)
	{
		if (mem[i] != '\0')
			return (0); // 0でなければ失敗
		i++;
	}
	return (1); // すべて0なら成功
}

// 結果を色付きで表示する関数
void print_result(const char *test_name, int success)
{
    if (success)
        printf("%-30s: [\033[32mOK\033[0m]\n", test_name);
    else
        printf("%-30s: [\033[31mKO\033[0m]\n", test_name);
}

int	main(void)
{
	printf("--- ft_bzero: Tests ---\n");

	// --- 正常系: 文字列の一部をゼロにする ---
	char str1[] = "Hello World!";
	ft_bzero(str1, 5);
	// 期待値: 先頭5文字がヌル文字 `\0` になる
	print_result("1. Normal case", str1[0] == '\0' && str1[4] == '\0' && str1[5] == ' ');


	// --- エッジケース: n = 0 の場合 ---
	char str2[] = "No Change";
	ft_bzero(str2, 0);
	// 期待値: 何も変わらない
	print_result("2. Edge case (n=0)", strcmp(str2, "No Change") == 0);


	// --- エッジケース: バッファ全体をゼロにする ---
	char str3[] = "12345";
	ft_bzero(str3, sizeof(str3)); // sizeofは末尾の\0も含む
	// 期待値: メモリ全体がゼロになっている
	print_result("3. Edge case (whole buffer)", verify_zero(str3, sizeof(str3)));


	// --- 異常系: NULLポインタを渡した場合 (クラッシュテスト) ---
	char *str4 = NULL;
	ft_bzero(str4, 10);
	print_result("4. NULL pointer (CRASH)", str4 == NULL);

	printf("-----------------------\n");
	return (0);
}
