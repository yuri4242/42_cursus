#include "libft.h"
#include <stdio.h>
#include <string.h>

// メモリの内容を分かりやすく表示するためのヘルパー関数
void print_memory(const char *label, const void *mem, size_t size)
{
    const unsigned char *p = (const unsigned char *)mem;
    printf("%-22s: \"", label);
    for (size_t i = 0; i < size; ++i)
    {
        // 表示可能な文字はそのまま、その他(ヌル文字など)は '.' で表示
        if (p[i] >= 32 && p[i] <= 126)
        {
            printf("%c", p[i]);
        }
        else
        {
            printf(".");
        }
    }
    printf("\"\n");
}

int main(void)
{
    char buffer[20];

    printf("========= Normal Cases =========\n");
    // --- 正常系1: 基本的な使い方 ---
    strcpy(buffer, "This is a test.");
    print_memory("1. Before ft_memset", buffer, sizeof(buffer));
    ft_memset(buffer, '*', 5); // 先頭5バイトを '*' で埋める
    print_memory("1. After ft_memset('*', 5)", buffer, sizeof(buffer));
    printf("\n");


    printf("========= Boundary Cases =========\n");
    // --- 境界値1: 長さに0を指定 ---
    strcpy(buffer, "This is a test.");
    print_memory("2. Before ft_memset", buffer, sizeof(buffer));
    ft_memset(buffer, 'X', 0); // 長さ0なので何も変わらないはず
    print_memory("2. After ft_memset('X', 0)", buffer, sizeof(buffer));
    printf("\n");
    
    // --- 境界値2: バッファ全体を指定 ---
    strcpy(buffer, "This is a test.");
    print_memory("3. Before ft_memset", buffer, sizeof(buffer));
    ft_memset(buffer, 'Z', sizeof(buffer)); // バッファ全体を'Z'で埋める
    print_memory("3. After ft_memset('Z', 20)", buffer, sizeof(buffer));
    printf("\n");


    printf("========= Abnormal/Edge Cases =========\n");
    // --- 異常系1: charの範囲を超える整数を指定 ---
    strcpy(buffer, "This is a test.");
    print_memory("4. Before ft_memset", buffer, sizeof(buffer));
    // 300 (0x12C) は (unsigned char) にキャストされ 44 (0x2C) になる (ASCIIで',')
    ft_memset(buffer, 300, 5); 
    print_memory("4. After ft_memset(300, 5)", buffer, sizeof(buffer));
    printf("\n");

    // --- 異常系2: -1を指定 ---
    strcpy(buffer, "This is a test.");
    print_memory("5. Before ft_memset", buffer, sizeof(buffer));
    // -1は (unsigned char) にキャストされ 255 (0xFF) になる
    memset(buffer, -3, 5); 
    //ft_memset(buffer, -1, 5); 
    print_memory("5. After ft_memset(-1, 5)", buffer, sizeof(buffer));
    printf("\n");

	// --- NULL ポインタを渡す ---
	char *test6 = NULL;
	char *ret6;
	ret6 = ft_memset(test6, 0, 6);
	if (ret6 == NULL)
		printf("6. ret6 is NULL\n");
    return (0);
}
