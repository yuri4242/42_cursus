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
    const char *src = "This is a long source string.";
    size_t ret1;
    size_t ret2;
    size_t src_len = strlen(src);

    printf("========= Test Cases for strlcpy =========\n");
    printf("Source string: \"%s\" (len: %zu)\n\n", src, src_len);

    // --- テストケース1: 十分なバッファサイズ（切り捨てなし）---
    printf("--- Test Case 1: No Truncation (size = 50) ---\n");
    ret1 = ft_strlcpy(dest1, src, sizeof(dest1));
    ret2 = strlcpy(dest2, src, sizeof(dest2));
    print_result("Content matches", strcmp(dest1, dest2) == 0);
    print_result("Return value matches", ret1 == ret2 && ret1 == src_len);
    printf("\n");

    // --- テストケース2: 不十分なバッファサイズ（切り捨てあり）---
    printf("--- Test Case 2: Truncation (size = 10) ---\n");
    ret1 = ft_strlcpy(dest1, src, 10);
    ret2 = strlcpy(dest2, src, 10);
    printf("ft_strlcpy dest: \"%s\"\n", dest1);
    printf("   strlcpy dest: \"%s\"\n", dest2);
    print_result("Content matches", strcmp(dest1, dest2) == 0);
    print_result("Return value matches", ret1 == ret2 && ret1 == src_len);
    printf("\n");

    // --- テストケース3: ぴったり収まるサイズ (境界値) ---
    printf("--- Test Case 3: Exact Fit (size = len + 1) ---\n");
    ret1 = ft_strlcpy(dest1, src, src_len + 1);
    ret2 = strlcpy(dest2, src, src_len + 1);
    print_result("Content matches", strcmp(dest1, dest2) == 0);
    print_result("Return value matches", ret1 == ret2 && ret1 == src_len);
    printf("\n");

    // --- テストケース4: dsize = 1 (境界値) ---
    printf("--- Test Case 4: dsize = 1 ---\n");
    ret1 = ft_strlcpy(dest1, src, 1);
    ret2 = strlcpy(dest2, src, 1);
    print_result("Content is empty string", dest1[0] == '\0' && dest2[0] == '\0');
    print_result("Return value matches", ret1 == ret2 && ret1 == src_len);
    printf("\n");

    // --- テストケース5: dsize = 0 (境界値) ---
    printf("--- Test Case 5: dsize = 0 ---\n");
    // dsize=0なのでコピーは起こらない。destの中身は初期化しないでおく
    char dummy_dest1[] = "dummy";
    char dummy_dest2[] = "dummy";
    ret1 = ft_strlcpy(dummy_dest1, src, 0);
    ret2 = strlcpy(dummy_dest2, src, 0);
    print_result("Content is unchanged", strcmp(dummy_dest1, "dummy") == 0);
    print_result("Return value matches", ret1 == ret2 && ret1 == src_len);
    printf("\n");

    //--- テストケース6: srcがNULLの場合 ---
    printf("--- Test Case 6: src is NULL ---\n");
    ret1 = ft_strlcpy(dest1, NULL, 10);
    // 期待値: もしガードするなら、戻り値は0のはず
    printf("Return value for NULL src: %zu\n", ret1);
    print_result("src is NULL", ret1 == 0);
    printf("\n");

    // --- テストケース7: dstがNULLの場合 ---
    printf("--- Test Case 7: dst is NULL ---\n");
	char *test7 = NULL;
    ret1 = ft_strlcpy(test7, src, 10);
    printf("Return value for NULL dst: %zu\n", ret1);
    print_result("dst is NULL", ret1 == src_len);
    printf("\n");

    return (0);
}
