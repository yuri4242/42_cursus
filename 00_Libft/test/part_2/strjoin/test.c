#include "libft.h"
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

// テストを実行し、結果を分かりやすく表示するヘルパー関数
void run_test(const char *test_name, const char *s1, const char *s2, const char *expected)
{
    char *result = ft_strjoin(s1, s2);
    int success = 0;

    printf("--- %s ---\n", test_name);
    printf("s1 = \"%s\", s2 = \"%s\"\n", s1, s2);
    
    // 期待値も結果もNULLの場合
    if (result == NULL && expected == NULL)
    {
        success = 1;
        printf("Result: NULL (as expected)\n");
    }
    // 文字列の内容が期待値と一致する場合
    else if (result && expected && strcmp(result, expected) == 0)
    {
        success = 1;
        printf("Result: \"%s\" (as expected)\n", result);
    }
    else
    {
        // どちらか片方だけがNULLだったり、内容が違う場合
        printf("Result: \"%s\", Expected: \"%s\"\n", result, expected);
    }

    if (success)
        printf("✅ OK\n\n");
    else
        printf("❌ NG\n\n");

    free(result); // ft_strjoinが確保したメモリを解放
}

int main(void)
{
    printf("========= Test Cases for strjoin =========\n\n");

    // --- テストケース1: 通常の連結 ---
    run_test("Test 1: Normal Join", "Hello, ", "World!", "Hello, World!");

    // --- テストケース2: s1が空文字列 ---
    run_test("Test 2: s1 is empty", "", "World!", "World!");

    // --- テストケース3: s2が空文字列 ---
    run_test("Test 3: s2 is empty", "Hello, ", "", "Hello, ");

    // --- テストケース4: 両方が空文字列 ---
    run_test("Test 4: Both are empty", "", "", "");
    
    // --- テストケース5: s1がNULL ---
    run_test("Test 5: s1 is NULL", NULL, "World!", NULL);

    // --- テストケース6: s2がNULL ---
    run_test("Test 6: s2 is NULL", "Hello, ", NULL, NULL);

    // --- テストケース7: 両方がNULL ---
    run_test("Test 7: Both are NULL", NULL, NULL, NULL);

    return (0);
}
