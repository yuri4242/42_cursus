#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 結果の配列を分かりやすく表示するためのヘルパー関数
void    print_splits(char **splits)
{
    int i = 0;
    if (!splits)
    {
        printf(" -> NULL\n");
        return;
    }
    printf(" -> [");
    while (splits[i])
    {
        printf("\"%s\"", splits[i]);
        if (splits[i + 1])
            printf(", ");
        i++;
    }
    printf("]\n");
}

// テストを実行し、結果を表示するヘルパー関数
void    run_test(const char *test_name, char const *s, char c)
{
    printf("--- %s ---\n", test_name);
    printf("Input: s=\"%s\", c='%c'\n", s, c);
    
    char **result = ft_split(s, c);
    
    printf("Result:");
    print_splits(result);
    
    // メモリ解放
    if (result)
    {
        // 実際にはft_split内部で使っている解放関数を呼び出すのが良い
        int i = 0;
        while (result[i])
        {
            free(result[i]);
            i++;
        }
        free(result);
    }
    printf("\n");
}


int main(void)
{
    printf("========= Test Cases for ft_split =========\n\n");

    // --- テストケース1: 基本的な分割 ---
    run_test("Test 1: Basic Split", "Hello World This is a test", ' ');

    // --- テストケース2: 区切り文字が連続する場合 ---
    run_test("Test 2: Consecutive Delimiters", "hello,,,world", ',');

    // --- テストケース3: 先頭と末尾に区切り文字がある場合 ---
    run_test("Test 3: Leading/Trailing Delimiters", "  hello world  ", ' ');

    // --- テストケース4: 区切り文字が存在しない場合 ---
    run_test("Test 4: No Delimiters", "nodelimiter", ' ');

    // --- テストケース5: 文字列全体が区切り文字の場合 ---
    run_test("Test 5: String of Delimiters", "       ", ' ');

    // --- テストケース6: 空文字列の場合 ---
    run_test("Test 6: Empty String", "", ' ');

    // --- テストケース7: sがNULLの場合 ---
    run_test("Test 7: s is NULL", NULL, ' ');

    // --- テストケース8: 終端が区切り文字 ---
    run_test("Test 8: Ends with Delimiter", "ends with space ", ' ');

    return (0);
}
