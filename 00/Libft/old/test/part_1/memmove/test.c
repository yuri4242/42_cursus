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
    char buf1[100];
    char buf2[100];
    void *ret1;
    void *ret2;

    printf("========= Test Cases for memmove =========\n\n");

    // --- テストケース1: オーバーラップなし (memcpyと同じ) ---
    printf("--- Test Case 1: Non-overlapping ---\n");
    strcpy(buf1, "Hello");
    strcpy(buf2, "Hello");
    ft_memmove(buf1 + 5, " World", 7); // "Hello World"
    memmove(buf2 + 5, " World", 7);
    printf("ft_memmove result: \"%s\"\n", buf1);
    printf("   memmove result: \"%s\"\n", buf2);
    print_result("Non-overlapping content", memcmp(buf1, buf2, 12) == 0);
    printf("\n");

    // --- テストケース2: オーバーラップあり (dest > src) - 後ろからコピーするケース ---
    printf("--- Test Case 2: Overlap (dest > src) ---\n");
    strcpy(buf1, "123456789");
    strcpy(buf2, "123456789");
    ret1 = ft_memmove(buf1 + 2, buf1, 5); // "121234589" になるはず
    ret2 = memmove(buf2 + 2, buf2, 5);
    printf("ft_memmove result: \"%s\"\n", buf1);
    printf("   memmove result: \"%s\"\n", buf2);
    print_result("Overlap (dest > src) content", memcmp(buf1, buf2, 10) == 0);
    print_result("Overlap (dest > src) return", ret1 == buf1 + 2);
    printf("\n");

    // --- テストケース3: オーバーラップあり (dest < src) - 前からコピーするケース ---
    printf("--- Test Case 3: Overlap (dest < src) ---\n");
    strcpy(buf1, "123456789");
    strcpy(buf2, "123456789");
    ret1 = ft_memmove(buf1, buf1 + 2, 5); // "345676789" になるはず
    ret2 = memmove(buf2, buf2 + 2, 5);
    printf("ft_memmove result: \"%s\"\n", buf1);
    printf("   memmove result: \"%s\"\n", buf2);
    print_result("Overlap (dest < src) content", memcmp(buf1, buf2, 10) == 0);
    print_result("Overlap (dest < src) return", ret1 == buf1);
    printf("\n");

    // --- テストケース4: 長さに0を指定 (境界値) ---
    printf("--- Test Case 4: Zero Length ---\n");
    strcpy(buf1, "123456789");
    strcpy(buf2, "123456789");
    ft_memmove(buf1, buf1 + 2, 0); // 何も変わらないはず
    memmove(buf2, buf2 + 2, 0);
    print_result("Zero length", memcmp(buf1, buf2, 10) == 0);
    printf("\n");

    // --- テストケース5: 引数にNULLを渡す ---
    printf("--- Test Case 5: NULL Argument ---\n");
	char *buf_a = NULL;
	char *buf_b = "123456789";
	char *buf_c;
    buf_c = ft_memmove(buf_a, buf_b, 10); 
    print_result("Return NULL", buf_c == NULL);
    printf("\n");
	
    // --- テストケース6: 引数にNULLを渡す ---
    printf("--- Test Case 6: NULL Argument ---\n");
	char *buf_6b = NULL;
	char *buf_6a = "123456789";
	char *buf_6c;
    buf_6c = ft_memmove(buf_6a, buf_6b, 10); 
    print_result("Return NULL", buf_6c == NULL);
    printf("\n");

    return (0);
}
