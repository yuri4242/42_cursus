#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int success)
{
    printf("%-30s: ", test_name);
    if (success)
        printf("✅ OK\n");
    else
        printf("❌ NG\n");
}

int main(void)
{
    // --- Test 1: 基本的な文字列のコピー ---
    char dest1[50] = "abcdefghijklmnopqrstuvwxyz";
    char src1[] = "12345";
    char dest2[50]; 
    strcpy(dest2, dest1); // 初期状態を同じにする
    ft_memcpy(dest1, src1, 5);
    memcpy(dest2, src1, 5);
    print_result("Basic String Copy", memcmp(dest1, dest2, 27) == 0);

    // --- Test 2: 長さに0を指定 ---
    strcpy(dest1, "abcdefg");
    strcpy(dest2, "abcdefg");
    ft_memcpy(dest1, src1, 0);
    memcpy(dest2, src1, 0);
    print_result("Zero Length Copy", memcmp(dest1, dest2, 8) == 0);

    // --- Test 3: 整数配列のコピー ---
    int int_src[] = {10, 20, 30, 40, 50};
    int int_dest1[5];
    int int_dest2[5];
    ft_memcpy(int_dest1, int_src, sizeof(int) * 5);
    memcpy(int_dest2, int_src, sizeof(int) * 5);
    print_result("Integer Array Copy", memcmp(int_dest1, int_dest2, sizeof(int) * 5) == 0);

    // --- Test 4: 戻り値のチェック ---
    void *ret1 = ft_memcpy(dest1, src1, 3);
    void *ret2 = memcpy(dest2, src1, 3);
    print_result("Return Value Check", ret1 == dest1 && ret2 == dest2);

    // --- テストケース5: 引数にNULLを渡す ---
    printf("--- Test Case 5: NULL Argument ---\n");
	char *buf_a = NULL;
	char *buf_b = "123456789";
	char *buf_c;
    buf_c = ft_memcpy(buf_a, buf_b, 10);
    print_result("Return NULL", buf_c == NULL);
    printf("\n");

    // --- テストケース6: 引数にNULLを渡す ---
    printf("--- Test Case 6: NULL Argument ---\n");
	char *buf_6b = NULL;
	char *buf_6a = "123456789";
	char *buf_6c;
    buf_6c = ft_memcpy(buf_6a, buf_6b, 10);
    print_result("Return NULL", buf_6c == NULL);
    printf("\n");

    return (0);
}
