#include "libft.h"
#include <stdio.h>
#include <string.h> 

// 戻り値の符号が一致するかをチェックする関数
// (res1 > 0 && res2 > 0) or (res1 < 0 && res2 < 0) or (res1 == 0 && res2 == 0)
int check_sign(int res1, int res2)
{
    if (res1 > 0 && res2 > 0)
        return (1);
    if (res1 < 0 && res2 < 0)
        return (1);
    if (res1 == 0 && res2 == 0)
        return (1);
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
    char s1[] = "abcdef";
    char s2[] = "abc\0def";
    char s3[] = "abcdef";
    int res1, res2;

    printf("========= Test Cases for memcmp =========\n\n");

    // --- テストケース1: 完全に一致する場合 ---
    res1 = ft_memcmp(s1, s3, 6);
    res2 = memcmp(s1, s3, 6);
    print_result("Test 1: Identical strings", check_sign(res1, res2));

    // --- テストケース2: s1 > s2 となる場合 ---
    res1 = ft_memcmp(s1, s2, 6);
    res2 = memcmp(s1, s2, 6);
    print_result("Test 2: s1 > s2 (diff at 4th byte)", check_sign(res1, res2));

    // --- テストケース3: s1 < s2 となる場合 ---
    res1 = ft_memcmp(s2, s1, 6);
    res2 = memcmp(s2, s1, 6);
    print_result("Test 3: s1 < s2 (diff at 4th byte)", check_sign(res1, res2));

    // --- テストケース4: 長さに0を指定 (境界値) ---
    res1 = ft_memcmp(s1, s2, 0);
    res2 = memcmp(s1, s2, 0);
    print_result("Test 4: Zero length", check_sign(res1, res2));

    // --- テストケース5: 途中まで一致する場合 ---
    res1 = ft_memcmp(s1, s3, 3);
    res2 = memcmp(s1, s3, 3);
    print_result("Test 5: Partial match", check_sign(res1, res2));
    
    // --- テストケース6: 異なる大きい値 ---
    char b1[] = "ab\xff";
    char b2[] = "ab\xfe";
    res1 = ft_memcmp(b1, b2, 3);
    res2 = memcmp(b1, b2, 3);
    print_result("Test 6: Unsigned char comparison", check_sign(res1, res2));

    // --- テストケース7: NULL文字列を渡す ---
    const char *null_71 = NULL;
    const char *null_72 = NULL;
    res1 = ft_memcmp(null_71, null_72, 10);
    print_result("Test 9: Return NULL", res1 == NULL);

    // --- テストケース8: NULL文字列を渡す ---
    const char *null_s1 = NULL;
    res1 = ft_memcmp(null_s1, "abd", 10);
    print_result("Test 9: Return NULL", res1 == 0 - 'a');

    // --- テストケース9: NULL文字列を渡す ---
    const char *null_s2 = NULL;
    res1 = ft_memcmp("abd", null_s2, 10);
    print_result("Test 10: Return NULL", res1 == 'a' - 0);


    return (0);
}
