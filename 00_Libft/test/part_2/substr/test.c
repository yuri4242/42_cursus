#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// テストを実行し、結果を分かりやすく表示するヘルパー関数
void run_test(const char *test_name, const char *s, unsigned int start, size_t len, const char *expected)
{
    char *result = ft_substr(s, start, len);
    int success = 0;

    printf("--- %s ---\n", test_name);
    printf("s = \"%s\", start = %u, len = %zu\n", s, start, len);
    
    if (result == NULL && expected == NULL)
    {
        success = 1;
        printf("Result: NULL (as expected)\n");
    }
    else if (result && expected && strcmp(result, expected) == 0)
    {
        success = 1;
        printf("Result: \"%s\" (as expected)\n", result);
    }
    else
    {
        printf("Result: \"%s\", Expected: \"%s\"\n", result, expected);
    }

    if (success)
        printf("✅ OK\n\n");
    else
        printf("❌ NG\n\n");

    free(result); // ft_substrが確保したメモリを解放
}

int main(void)
{
    printf("========= Test Cases for substr =========\n\n");

    // --- テストケース1: 通常の切り出し ---
    run_test("Test 1: Normal substring", "Hello World", 6, 5, "World");

    // --- テストケース2: lenが長すぎる場合 ---
    // "World"以降は3文字しかないので、"rld"が返るはず
    run_test("Test 2: len is too long", "Hello World", 8, 10, "rld");

    // --- テストケース3: startが文字列長以上の場合 ---
    run_test("Test 3: start is out of bounds", "Hello", 5, 5, "");

    // --- テストケース4: lenが0の場合 ---
    run_test("Test 4: len is 0", "Hello", 2, 0, "");
    
    // --- テストケース5: sが空文字列の場合 ---
    run_test("Test 5: s is an empty string", "", 0, 5, "");
    
    // --- テストケース6: sがNULLの場合 ---
    run_test("Test 6: s is NULL", NULL, 0, 5, NULL);

    return (0);
}
