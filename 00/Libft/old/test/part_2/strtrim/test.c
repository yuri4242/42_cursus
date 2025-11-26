#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// テストを実行し、結果を分かりやすく表示するヘルパー関数
void run_test(const char *test_name, const char *s1, const char *set, const char *expected)
{
    char *result = ft_strtrim(s1, set);
    int success = 0;

    printf("--- %s ---\n", test_name);
    printf("s1 = \"%s\", set = \"%s\"\n", s1, set);
    
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

    free(result); // ft_strtrimが確保したメモリを解放
}

int main(void)
{
    printf("========= Test Cases for strtrim =========\n\n");

    // --- テストケース1: 先頭と末尾の両方をトリム ---
    run_test("Test 1: Trim both ends", "  --Hello World--  ", " -", "Hello World");

    // --- テストケース2: 先頭のみをトリム ---
    run_test("Test 2: Trim from start only", "xxxyyHello", "xy", "Hello");

    // --- テストケース3: 末尾のみをトリム ---
    run_test("Test 3: Trim from end only", "Helloxyxyy", "xy", "Hello");

    // --- テストケース4: トリムする文字がない ---
    run_test("Test 4: No trimming", "Hello World", "xy", "Hello World");

    // --- テストケース5: 文字列全体がトリムされる ---
    run_test("Test 5: Entire string is trimmed", "xyxyxyxy", "xy", "");

    // --- テストケース6: s1が空文字列 ---
    run_test("Test 6: s1 is empty", "", "xy", "");

    // --- テストケース7: setが空文字列 ---
    run_test("Test 7: set is empty", "  Hello  ", "", "  Hello  ");

    // --- テストケース8: s1がNULL ---
    run_test("Test 8: s1 is NULL", NULL, "xy", NULL);

    // --- テストケース9: s2がNULL ---
    run_test("Test 9: s2 is NULL", "Hello World", NULL, NULL);

    return (0);
}
