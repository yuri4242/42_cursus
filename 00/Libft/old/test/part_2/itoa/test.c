#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// テストを実行し、結果を分かりやすく表示するヘルパー関数
void run_test(const char *test_name, int n, const char *expected)
{
    char *result = ft_itoa(n);
    int success = 0;

    printf("--- %s ---\n", test_name);
    printf("Input: %d\n", n);
    
    if (result && expected && strcmp(result, expected) == 0)
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

    free(result); // ft_itoaが確保したメモリを解放
}

int main(void)
{
    printf("========= Test Cases for itoa =========\n\n");

    // --- テストケース1: 通常の正の数 ---
    run_test("Test 1: Normal Positive", 12345, "12345");

    // --- テストケース2: 通常の負の数 ---
    run_test("Test 2: Normal Negative", -6789, "-6789");

    // --- テストケース3: 0 ---
    run_test("Test 3: Zero", 0, "0");

    // --- テストケース4: intの最大値 ---
    run_test("Test 4: INT_MAX", 2147483647, "2147483647");

    // --- テストケース5: intの最小値 (最重要) ---
    run_test("Test 5: INT_MIN", -2147483648, "-2147483648");
    
    // --- テストケース6: 1桁の数 ---
    run_test("Test 6: Single Digit", 9, "9");

    // --- テストケース7: 1桁の負の数 ---
    run_test("Test 7: Single Negative Digit", -5, "-5");

    // --- テストケース8: 負の数のオーバーフロー ---
    run_test("Test 8: Overflow Negative Digit", -21474836489, "-9");

    return (0);
}
