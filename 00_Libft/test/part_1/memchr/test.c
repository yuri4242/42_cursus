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
    void *ret1;
    void *ret2;

    printf("========= Test Cases for memchr =========\n");
    printf("Searching in: \"%s\"\n\n", s);

    // --- テストケース1: 文字が見つかる場合 ---
    ret1 = ft_memchr(s, 'a', 20);
    ret2 = memchr(s, 'a', 20);
    print_result("Test 1: Find 'a' in 20 bytes", ret1 == ret2);

    // --- テストケース2: 文字が見つからない場合 ---
    ret1 = ft_memchr(s, 'z', 20);
    ret2 = memchr(s, 'z', 20);
    print_result("Test 2: Find 'z' in 20 bytes", ret1 == ret2); // どちらもNULLのはず

    // --- テストケース3: 最初の文字が見つかる場合 ---
    ret1 = ft_memchr(s, 'T', 20);
    ret2 = memchr(s, 'T', 20);
    print_result("Test 3: Find first char 'T'", ret1 == ret2);

    // --- テストケース4: 最後の文字が見つかる場合 (範囲内) ---
    ret1 = ft_memchr(s, 'g', strlen(s));
    ret2 = memchr(s, 'g', strlen(s));
    print_result("Test 4: Find last char 'g'", ret1 == ret2);

    // --- テストケース5: 長さに0を指定 (境界値) ---
    ret1 = ft_memchr(s, 'T', 0);
    ret2 = memchr(s, 'T', 0);
    print_result("Test 5: Zero length", ret1 == ret2); // どちらもNULLのはず

    // --- テストケース6: ヌル文字 '\0' を探す ---
    // strlen(s) + 1 でヌル文字の範囲まで含める
    ret1 = ft_memchr(s, '\0', strlen(s) + 1);
    ret2 = memchr(s, '\0', strlen(s) + 1);
    print_result("Test 6: Find NULL terminator", ret1 == ret2);

    // --- テストケース7: 範囲外の文字を探す ---
    ret1 = ft_memchr(s, 'g', 15); // 'g'は18バイト目にある
    ret2 = memchr(s, 'g', 15);
    print_result("Test 7: Char outside n bytes", ret1 == ret2); // どちらもNULLのはず

    // --- テストケース8: NULLポインタを渡す ---
    ret1 = ft_memchr(NULL, 'g', 15); // 'g'は18バイト目にある
    print_result("Test 8: Return NULL", ret1 == NULL); // どちらもNULLのはず

    return (0);
}
