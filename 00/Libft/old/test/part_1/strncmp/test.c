#include "libft.h"
#include <stdio.h>
#include <string.h> 

// 戻り値の符号が一致するかをチェックするヘルパー関数
int check_sign(int res1, int res2)
{
    if (res1 > 0 && res2 > 0) return (1);
    if (res1 < 0 && res2 < 0) return (1);
    if (res1 == 0 && res2 == 0) return (1);
    return (0);
}

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
    int res1, res2;

    printf("========= Test Cases for strncmp =========\n\n");

    // --- テストケース1: 完全に一致する場合 ---
    res1 = ft_strncmp("abc", "abc", 5);
    res2 = strncmp("abc", "abc", 5);
    print_result("Test 1: Identical strings", check_sign(res1, res2));

    // --- テストケース2: s1 > s2 となる場合 ---
    res1 = ft_strncmp("abC", "abA", 5);
    res2 = strncmp("abC", "abA", 5);
	printf("res1 = %d\nres2 = %d\n", res1, res2);
    print_result("Test 2: s1 > s2", check_sign(res1, res2));

    // --- テストケース3: s1 < s2 となる場合 ---
    res1 = ft_strncmp("abA", "abC", 5);
    res2 = strncmp("abA", "abC", 5);
    print_result("Test 3: s1 < s2", check_sign(res1, res2));

    // --- テストケース4: 片方が接頭辞の場合 (重要) ---
    res1 = ft_strncmp("abc", "abcd", 4);
    res2 = strncmp("abc", "abcd", 4);
    print_result("Test 4: Prefix case (s1 < s2)", check_sign(res1, res2));
    
    res1 = ft_strncmp("abcd", "abc", 4);
    res2 = strncmp("abcd", "abc", 4);
    print_result("Test 5: Prefix case (s1 > s2)", check_sign(res1, res2));

    // --- テストケース5: nによって比較が打ち切られる場合 ---
    res1 = ft_strncmp("abZ", "abA", 2); // 2バイトまでしか見ないので、差が出ない
    res2 = strncmp("abZ", "abA", 2);
    print_result("Test 6: Cut off by n", check_sign(res1, res2)); // 0になるはず

    // --- テストケース6: nが0の場合 (境界値) ---
    res1 = ft_strncmp("abc", "abd", 0);
    res2 = strncmp("abc", "abd", 0);
    print_result("Test 7: n is 0", check_sign(res1, res2)); // 0になるはず
    
    // --- テストケース7: unsigned charとしての比較 ---
    res1 = ft_strncmp("ab\xff", "ab\x01", 3);
    res2 = strncmp("ab\xff", "ab\x01", 3);
    print_result("Test 8: Unsigned char comparison", check_sign(res1, res2));

    // --- テストケース8: NULL文字列を渡す ---
    const char *null_s1 = NULL;
    res1 = ft_strncmp(null_s1, "abd", 10);
    print_result("Test 9: Return NULL", res1 == 0 - 'a');

    // --- テストケース9: NULL文字列を渡す ---
    const char *null_s2 = NULL;
    res1 = ft_strncmp("abd", null_s2, 10);
    print_result("Test 10: Return NULL", res1 == 'a' - 0);

    return (0);
}
