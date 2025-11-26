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
    const char *s = "This is a test string.";
    char *ret1;
    char *ret2;

    printf("========= Test Cases for strrchr =========\n");
    printf("Searching in: \"%s\"\n\n", s);

    // --- テストケース1: 複数ある文字の最後を探す ---
    ret1 = ft_strrchr(s, 's');
    ret2 = strrchr(s, 's');
    print_result("Test 1: Find last 's'", ret1 == ret2);
    if (ret1) printf("  -> Found at: \"%s\"\n", ret1);

    // --- テストケース2: 文字列にない文字を探す ---
    ret1 = ft_strrchr(s, 'z');
    ret2 = strrchr(s, 'z');
    print_result("Test 2: Find 'z' (not found)", ret1 == ret2); // どちらもNULLのはず

    // --- テストケース3: ヌル終端文字('\0')を探す (重要) ---
    ret1 = ft_strrchr(s, '\0');
    ret2 = strrchr(s, '\0');
    print_result("Test 3: Find NULL terminator", ret1 == ret2);
    if (ret1) printf("  -> Found terminator at end of string.\n");

    // --- テストケース4: 最初の文字を探す（他に同じ文字がない） ---
    ret1 = ft_strrchr(s, 'T');
    ret2 = strrchr(s, 'T');
    print_result("Test 4: Find first character 'T'", ret1 == ret2);

    // --- テストケース5: 空文字列で探す ---
    const char *empty_s = "";
    ret1 = ft_strrchr(empty_s, 'a');
    ret2 = strrchr(empty_s, 'a');
    print_result("Test 5: Find 'a' in empty string", ret1 == ret2); // どちらもNULL

    ret1 = ft_strrchr(empty_s, '\0');
    ret2 = strrchr(empty_s, '\0');
    print_result("Test 6: Find '\\0' in empty string", ret1 == ret2); // 終端の'\0'を指すはず

    // --- テストケース7: NULL文字列を渡す ---
    const char *null_s = NULL;
    ret1 = ft_strrchr(null_s, 'a');
    print_result("Test 7: Return NULL", ret1 == NULL);

    return (0);
}
