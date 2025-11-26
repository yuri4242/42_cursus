#include "libft.h"
#include <stdio.h>
#include <string.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int success)
{
    printf("%-35s: ", test_name);
    if (success)
        printf("✅ OK\n");
    else
        printf("❌ NG\n");
}

int main(void)
{
    const char *s = "Hello World";
    char *ret1;
    char *ret2;

    printf("========= Test Cases for strchr =========\n");
    printf("Searching in: \"%s\"\n\n", s);

    // --- テストケース1: 文字列の中の文字を探す ---
    ret1 = ft_strchr(s, 'o');
    ret2 = strchr(s, 'o');
    print_result("Test 1: Find 'o' in middle", ret1 == ret2);
    if (ret1) printf("  -> Found at: \"%s\"\n", ret1);

    // --- テストケース2: 文字列にない文字を探す ---
    ret1 = ft_strchr(s, 'z');
    ret2 = strchr(s, 'z');
    print_result("Test 2: Find 'z' (not found)", ret1 == ret2); // どちらもNULLのはず

    // --- テストケース3: ヌル終端文字('\0')を探す (重要) ---
    ret1 = ft_strchr(s, '\0');
    ret2 = strchr(s, '\0');
    print_result("Test 3: Find NULL terminator", ret1 == ret2);
    if (ret1) printf("  -> Found terminator at end of string.\n");

    // --- テストケース4: 最初の文字を探す ---
    ret1 = ft_strchr(s, 'H');
    ret2 = strchr(s, 'H');
    print_result("Test 4: Find first character", ret1 == ret2);

    // --- テストケース5: 空文字列で探す ---
    const char *empty_s = "";
    ret1 = ft_strchr(empty_s, 'a');
    ret2 = strchr(empty_s, 'a');
    print_result("Test 5: Find 'a' in empty string", ret1 == ret2); // どちらもNULL

    ret1 = ft_strchr(empty_s, '\0');
    ret2 = strchr(empty_s, '\0');
    print_result("Test 6: Find '\\0' in empty string", ret1 == ret2); // 終端の'\0'を指すはず
    
    // --- テストケース7: NULL文字列を渡す ---
    const char *null_s = NULL;
    ret1 = ft_strchr(null_s, 'a');
    print_result("Test 7: Return NULL", ret1 == NULL);

	return (0);
}
