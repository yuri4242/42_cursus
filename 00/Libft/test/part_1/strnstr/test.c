#include "libft.h"
#include <stdio.h>
#include <string.h> 

#if defined(__linux__)
#include <bsd/string.h>
#endif

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
    const char *big = "MZIRIBMZE123";
    char *ret1;
    char *ret2;

    printf("========= Test Cases for strnstr =========\n");
    printf("Haystack: \"%s\"\n\n", big);

    // --- テストケース1: 通常に見つかる ---
    ret1 = ft_strnstr(big, "ZE1", 10);
    ret2 = strnstr(big, "ZE1", 10);
    print_result("Test 1: Basic find", ret1 == ret2);

    // --- テストケース2: 見つからない ---
    ret1 = ft_strnstr(big, "ZE2", 10);
    ret2 = strnstr(big, "ZE2", 10);
    print_result("Test 2: Not found", ret1 == ret2); // どちらもNULLのはず

    // --- テストケース3: lenによって見つからなくなる ---
    ret1 = ft_strnstr(big, "ZE1", 7); // "ZE1"は8バイト目からなので見つからない
    ret2 = strnstr(big, "ZE1", 7);
    print_result("Test 3: Cut off by len", ret1 == ret2); // どちらもNULLのはず

    // --- テストケース4: littleが空文字列 (重要) ---
    ret1 = ft_strnstr(big, "", 10);
    ret2 = strnstr(big, "", 10);
    print_result("Test 4: Empty needle", ret1 == ret2); // bigの先頭を指すはず

    // --- テストケース5: lenが0 (境界値) ---
    ret1 = ft_strnstr(big, "ZE1", 0);
    ret2 = strnstr(big, "ZE1", 0);
    print_result("Test 5: len is 0", ret1 == ret2); // どちらもNULLのはず

    // --- テストケース6: littleがbigより長い ---
    ret1 = ft_strnstr(big, "MZIRIBMZE1234", 15);
    ret2 = strnstr(big, "MZIRIBMZE1234", 15);
    print_result("Test 6: Needle longer than haystack", ret1 == ret2); // どちらもNULLのはず

    // --- テストケース7: lenがlittleより短い ---
    const char *s1 = "abcdef";
    const char *s2 = "cde"; // len=3
    ret1 = ft_strnstr(s1, s2, 2); // len=2では見つからない
    ret2 = strnstr(s1, s2, 2);
    print_result("Test 7: len shorter than needle", ret1 == ret2); // どちらもNULLのはず

    // --- テストケース8: NULL文字列を渡す ---
    const char *null_lit = NULL;
    ret1 = ft_strnstr(big, null_lit, 10);
    print_result("Test 8: Return NULL", ret1 == NULL);

    // --- テストケース9: NULL文字列を渡す ---
    const char *null_big = NULL;
    ret1 = ft_strnstr(null_big, "ZE1", 10);
    print_result("Test 9: Return NULL", ret1 == NULL);
    return (0);
}
