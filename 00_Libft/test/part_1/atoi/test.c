#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int res1, int res2)
{
    printf("%-35s: ", test_name);
    if (res1 == res2)
        printf("✅ OK (Value: %d)\n", res1);
    else
        printf("❌ NG (ft_atoi: %d, atoi: %d)\n", res1, res2);
}

int main(void)
{
    printf("========= Test Cases for atoi =========\n\n");

    // --- 正常系 ---
    print_result("Test 1: Basic positive", ft_atoi("123"), atoi("123"));
    print_result("Test 2: Basic negative", ft_atoi("-456"), atoi("-456"));
    print_result("Test 3: Positive with sign", ft_atoi("+789"), atoi("+789"));
    
    // --- 空白文字のテスト ---
    print_result("Test 4: Leading spaces", ft_atoi("   \t\n\v\f\r 42"), atoi("   \t\n\v\f\r 42"));
    print_result("Test 5: Spaces and sign", ft_atoi("  \n-123"), atoi("  \n-123"));
    
    // --- 数字の後ろに文字があるケース ---
    print_result("Test 6: Number then chars", ft_atoi("42tokyo"), atoi("42tokyo"));
    print_result("Test 7: Number with space after", ft_atoi("-45 67"), atoi("-45 67"));
    
    // --- 不正な入力のテスト ---
    print_result("Test 8: No digits", ft_atoi("hello"), atoi("hello"));
    print_result("Test 9: Sign only", ft_atoi("+"), atoi("+"));
    print_result("Test 10: Multiple signs", ft_atoi("+-42"), atoi("+-42"));
    print_result("Test 11: Chars before number", ft_atoi("a42"), atoi("a42"));

    // --- 境界値とオーバーフローのテスト ---
    // あなたの実装がINT_MAX/MINを返す場合、本家とは結果が異なることがあります
    printf("\n--- Overflow/Boundary Cases (Behavior might differ) ---\n");
    print_result("Test 12: INT_MAX", ft_atoi("2147483647"), atoi("2147483647"));
    print_result("Test 13: INT_MIN", ft_atoi("-2147483648"), atoi("-2147483648"));
    
    // 未定義の動作の領域
    print_result("Test 14: Overflow", ft_atoi("2147483648"), atoi("2147483648"));
    print_result("Test 15: Underflow", ft_atoi("-2147483649"), atoi("-2147483649"));
    print_result("Test 16: Long long value", ft_atoi("999999999999"), atoi("999999999999"));

	// NULLを与えた場合
    printf("\n--- NULL Cases (Behavior might differ) ---\n");
    print_result("Test 17: NULL", ft_atoi(NULL), 0);
    return (0);
}
