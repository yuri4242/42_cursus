#include "libft.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <string.h>
#include <limits.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int success)
{
    printf("%-35s: ", test_name);
    if (success)
        printf("✅ OK\n");
    else
        printf("❌ NG\n");
}

// メモリがゼロクリアされているかチェックする関数
int is_memory_zero(const void *mem, size_t size)
{
    const unsigned char *p = mem;
    for (size_t i = 0; i < size; ++i)
    {
        if (p[i] != 0)
            return (0); // 0でないバイトが見つかった
    }
    return (1); // すべて0だった
}

int main(void)
{
    void *ptr1;
    void *ptr2;

    printf("========= Test Cases for calloc =========\n\n");

    // --- テストケース1: 通常の確保とゼロ初期化の確認 ---
    printf("--- Test Case 1: Normal Allocation ---\n");
    ptr1 = ft_calloc(10, sizeof(int));
    ptr2 = calloc(10, sizeof(int));
    // 戻り値のポインタがNULLでないこと、中身がゼロであることを確認
    print_result("Normal alloc (non-NULL)", ptr1 != NULL && ptr2 != NULL);
    if (ptr1 && ptr2)
        print_result("Normal alloc (is zeroed)", is_memory_zero(ptr1, 10 * sizeof(int)));
    free(ptr1);
    free(ptr2);
    printf("\n");

    // --- テストケース2: nmembが0の場合 (エッジケース) ---
    printf("--- Test Case 2: nmemb is 0 ---\n");
    ptr1 = ft_calloc(0, 10);
    ptr2 = calloc(0, 10);
    // 多くの環境ではNULL以外が返るが、NULLも仕様上は許容される
    printf("ft_calloc(0, 10) returned: %p\n", ptr1);
    printf("   calloc(0, 10) returned: %p\n", ptr2);
    print_result("nmemb is 0 (can be freed)", (ptr1 != NULL)); // ここでは非NULLであることを期待
    print_result("nmemb is 0 (can be freed)", (ptr2 != NULL)); // ここでは非NULLであることを期待
    free(ptr1);
    free(ptr2);
    printf("\n");

    // --- テストケース3: sizeが0の場合 (エッジケース) ---
    printf("--- Test Case 3: size is 0 ---\n");
    ptr1 = ft_calloc(10, 0);
    ptr2 = ft_calloc(10, 0);
    printf("ft_calloc(10, 0) returned: %p\n", ptr1);
    printf("   calloc(10, 0) returned: %p\n", ptr2);
    print_result("size is 0 (can be freed)", (ptr1 != NULL));
    print_result("size is 0 (can be freed)", (ptr2 != NULL));
    free(ptr1);
    free(ptr2);
    printf("\n");

    // --- テストケース4: 乗算オーバーフロー (エラーケース) ---
    printf("--- Test Case 4: Multiplication Overflow ---\n");
    ptr1 = ft_calloc(SIZE_MAX, 2);
    ptr2 = calloc(SIZE_MAX, 2);
    print_result("Overflow check", ptr1 == ptr2); // どちらもNULLのはず
    free(ptr1);
    free(ptr2);
    printf("\n");
    
    return (0);
}
