#include "libft.h"
#include <stdio.h>
#include <string.h>

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
    const char *src = "Find the delimiter character.";
    void *ret1;
    void *ret2;

    printf("========= Test Cases for memccpy =========\n\n");

    // --- テストケース1: 文字が見つかる場合 ---
    printf("--- Test Case 1: Character Found ---\n");
    // 初期化
    memset(dest1, 0, sizeof(dest1));
    memset(dest2, 0, sizeof(dest2));
    // 実行
    ret1 = ft_memccpy(dest1, src, 'i', 20);
    ret2 = memccpy(dest2, src, 'i', 20);
    printf("ft_memccpy dest: \"%s\"\n", dest1);
    printf("   memccpy dest: \"%s\"\n", dest2);
    // 結果の比較
    print_result("Content matches", memcmp(dest1, dest2, sizeof(dest1)) == 0);
    print_result("Return pointer matches", (char *)ret1 - dest1 == (char *)ret2 - dest2);
    printf("\n");

    // --- テストケース2: 文字が見つからない場合 ---
    printf("--- Test Case 2: Character Not Found ---\n");
    memset(dest1, 0, sizeof(dest1));
    memset(dest2, 0, sizeof(dest2));
    ret1 = ft_memccpy(dest1, src, 'z', 10);
    ret2 = memccpy(dest2, src, 'z', 10);
    printf("ft_memccpy dest: \"%s\" (first 10 bytes copied)\n", dest1);
    printf("   memccpy dest: \"%s\" (first 10 bytes copied)\n", dest2);
    print_result("Content matches", memcmp(dest1, dest2, sizeof(dest1)) == 0);
    print_result("Return pointer is NULL", ret1 == NULL && ret2 == NULL);
    printf("\n");

    // --- テストケース3: 長さに0を指定 (境界値) ---
    printf("--- Test Case 3: Zero Length ---\n");
    memset(dest1, 0, sizeof(dest1));
    memset(dest2, 0, sizeof(dest2));
    ret1 = ft_memccpy(dest1, src, 'F', 0);
    ret2 = memccpy(dest2, src, 'F', 0);
    print_result("Content matches (no change)", memcmp(dest1, dest2, sizeof(dest1)) == 0);
    print_result("Return pointer is NULL", ret1 == NULL && ret2 == NULL);
    printf("\n");

    // --- テストケース4: 最初の文字が区切り文字の場合 ---
    printf("--- Test Case 4: Delimiter is the first char ---\n");
    memset(dest1, 0, sizeof(dest1));
    memset(dest2, 0, sizeof(dest2));
    ret1 = ft_memccpy(dest1, src, 'F', 10);
    ret2 = memccpy(dest2, src, 'F', 10);
    printf("ft_memccpy dest: \"%s\"\n", dest1);
    printf("   memccpy dest: \"%s\"\n", dest2);
    print_result("Content matches", memcmp(dest1, dest2, sizeof(dest1)) == 0);
    print_result("Return pointer matches", (char *)ret1 - dest1 == (char *)ret2 - dest2);
    printf("\n");

    return (0);
}
