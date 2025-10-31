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
    char dest1[50];
    char dest2[50];
    const char *src = "World";
    size_t ret1;
    size_t ret2;
    
    printf("========= Test Cases for strlcat =========\n\n");

    // --- テストケース1: 十分なバッファサイズ（切り捨てなし）---
    printf("--- Test Case 1: No Truncation ---\n");
    strcpy(dest1, "Hello, ");
    strcpy(dest2, "Hello, ");
    ret1 = ft_strlcat(dest1, src, 20);
    ret2 = strlcat(dest2, src, 20);
    printf("ft_strlcat dest: \"%s\" (ret: %zu)\n", dest1, ret1);
    printf("   strlcat dest: \"%s\" (ret: %zu)\n", dest2, ret2);
    print_result("Content matches", strcmp(dest1, dest2) == 0);
    print_result("Return value matches", ret1 == ret2);
    printf("\n");

    // --- テストケース2: 不十分なバッファサイズ（切り捨てあり）---
    printf("--- Test Case 2: Truncation ---\n");
    strcpy(dest1, "Hello, ");
    strcpy(dest2, "Hello, ");
    ret1 = ft_strlcat(dest1, src, 10); // size=10, "Hello, "(7)+"Wor"(2)+'\0'(1)
    ret2 = strlcat(dest2, src, 10);
    printf("ft_strlcat dest: \"%s\" (ret: %zu)\n", dest1, ret1);
    printf("   strlcat dest: \"%s\" (ret: %zu)\n", dest2, ret2);
    print_result("Content matches", strcmp(dest1, dest2) == 0);
    print_result("Return value matches", ret1 == ret2);
    printf("\n");

    // --- テストケース3: dstが既に一杯の場合 (size <= len_dst) ---
    printf("--- Test Case 3: Dst is already full ---\n");
    strcpy(dest1, "123456789"); // len=9
    strcpy(dest2, "123456789");
    ret1 = ft_strlcat(dest1, src, 9); // size=9, len_dst=9
    ret2 = strlcat(dest2, src, 9);
    printf("ft_strlcat dest: \"%s\" (ret: %zu)\n", dest1, ret1);
    printf("   strlcat dest: \"%s\" (ret: %zu)\n", dest2, ret2);
    print_result("Content matches (no change)", strcmp(dest1, dest2) == 0);
    print_result("Return value matches", ret1 == ret2); // 9 + 5 = 14
    printf("\n");

    // --- テストケース4: dsize = 0 (境界値) ---
    printf("--- Test Case 4: size = 0 ---\n");
    strcpy(dest1, "abc");
    strcpy(dest2, "abc");
    ret1 = ft_strlcat(dest1, src, 0);
    ret2 = strlcat(dest2, src, 0);
    print_result("Content is unchanged", strcmp(dest1, "abc") == 0);
    print_result("Return value matches", ret1 == ret2 && ret1 == strlen(src));
    printf("\n");

    // --- テストケース5: srcが空文字列の場合 ---
    printf("--- Test Case 5: src is empty string ---\n");
    strcpy(dest1, "Hello");
    strcpy(dest2, "Hello");
    ret1 = ft_strlcat(dest1, "", 10);
    ret2 = strlcat(dest2, "", 10);
    print_result("Content is unchanged", strcmp(dest1, dest2) == 0);
    print_result("Return value matches", ret1 == ret2);
    printf("\n");

    // --- テストケース6: dstがヌル終端されていない場合 ---
    printf("--- Test Case 6: Dst is not NULL-terminated ---\n");
    char non_term_dst[10];
    memset(non_term_dst, 'A', 10);
    ret1 = ft_strlcat(non_term_dst, "B", 10);
    printf("ft_strlcat (non-term): ret=%zu, dst[0]='%c'\n", ret1, non_term_dst[0]);
    print_result("Non-terminated dst handled", ret1 == 11 && non_term_dst[9] == 'A');
    printf("\n");

    // --- テストケース7: srcがNULLの場合 ---
    printf("--- Test Case 7: src is NULL ---\n");
    strcpy(dest1, "Hello");
    ret1 = ft_strlcat(dest1, NULL, 20);
    printf("ft_strlcat with NULL src returned: %zu\n", ret1);
    printf("\n");

    // --- テストケース8: dstがNULLの場合 ---
    printf("--- Test Case 8: dst is NULL ---\n");
    ret1 = ft_strlcat(NULL, "World", 20);
    printf("ft_strlcat with NULL dst returned: %zu\n", ret1);
    printf("\n");

    return (0);
}
