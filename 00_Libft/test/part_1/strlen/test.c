#include "libft.h"
#include <stdio.h>
#include <string.h> 
#include <stddef.h>

// テストを実行し、結果を分かりやすく表示するヘルパー関数
void run_test(const char *test_name, const char *s)
{
    size_t res1 = ft_strlen(s);
    size_t res2 = strlen(s);

    printf("--- %s ---\n", test_name);
    printf("Input: \"%s\"\n", s);
    
    if (res1 == res2)
        printf("✅ OK (Length: %zu)\n\n", res1);
    else
        printf("❌ NG (ft_strlen: %zu, strlen: %zu)\n\n", res1, res2);
}

int main(void)
{
    printf("========= Test Cases for strlen =========\n\n");

    // --- テストケース1: 通常の文字列 ---
    run_test("Test 1: Normal String", "Hello, World!");

    // --- テストケース2: 空文字列 (重要) ---
    run_test("Test 2: Empty String", "");

    // --- テストケース3: 特殊文字を含む文字列 ---
    run_test("Test 3: String with special chars", "\t\n\v\f\r");

    // --- テストケース4: 長い文字列 ---
    run_test("Test 4: Long String", "This is a slightly longer string to test the loop.");

    // --- テストケース5: 無効な文字列 ---
    char *test5 = NULL;
	printf("test5-len: %zu\n", ft_strlen(test5));

    return (0);
}
