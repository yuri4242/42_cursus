#include "libft.h"
#include <stdio.h>
#include <string.h>

// int型配列の内容を表示するためのヘルパー関数
void print_int_array(const char *label, const int *arr, size_t count)
{
    printf("%-22s: [", label);
    for (size_t i = 0; i < count; ++i)
    {
        printf("%d", arr[i]);
        if (i < count - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void)
{
    int numbers[5];
    size_t num_count = sizeof(numbers) / sizeof(int);

    printf("========= Integer Array Cases =========\n");

    // --- 整数ケース1: 0で初期化 (期待通りに動作) ---
    printf("--- Test Case 1: Fill with 0 ---\n");
    // 初期状態は不定値
    print_int_array("1. Before ft_memset", numbers, num_count);
    ft_memset(numbers, 0, sizeof(numbers)); // 全バイトを0で埋める
    print_int_array("1. After ft_memset(0)", numbers, num_count);
    printf("-> This works as expected.\n\n");


    // --- 整数ケース2: 1で初期化 (期待通りに動作しない！) ---
    printf("--- Test Case 2: Fill with 1 (Unexpected result!) ---\n");
    print_int_array("2. Before ft_memset", numbers, num_count);
    ft_memset(numbers, 1, sizeof(numbers)); // 全バイトを1 (0x01) で埋める
    print_int_array("2. After ft_memset(1)", numbers, num_count);
    printf("-> Each element becomes 16843009, not 1.\n");
    printf("   (Because each 4-byte int becomes 0x01010101)\n\n");
    
    
    // --- 整数ケース3: -1で初期化 (期待通りに動作) ---
    printf("--- Test Case 3: Fill with -1 ---\n");
    print_int_array("3. Before ft_memset", numbers, num_count);
    ft_memset(numbers, -1, sizeof(numbers)); // 全バイトを-1 (0xFF) で埋める
    print_int_array("3. After ft_memset(-1)", numbers, num_count);
    printf("-> This works as expected.\n");
    printf("   (Because each 4-byte int becomes 0xFFFFFFFF)\n");
    
    return (0);
}
